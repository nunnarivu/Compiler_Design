#ifndef TREENODE_H
#define TREENODE_H

#include<vector>
#include<string>
#include<stack>
#include<map>
#include<iostream>
#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/BitWriter.h>
#include <llvm-c/Initialization.h>
#include <llvm-c/Transforms/Scalar.h>

using namespace std;

class ASTNode;

extern LLVMContextRef globalcontext;
extern LLVMModuleRef globalmodule;
extern LLVMBuilderRef globalbuilder;

void codegeneration(ASTNode*);

class ASTNode
{
    public:
        string type;
        vector<ASTNode*> children;
        LLVMValueRef codegen();
        ASTNode(string s)
        {
            type = s;
        }
        ASTNode(){
            type = "";
        }
};

class KeywordNode: public ASTNode
{
    public:
        string name;
        string info;
        LLVMValueRef codegen();
        KeywordNode(string help, string n)
        {
            type = "keyword";
            name = n;
            info = help;
        }
        KeywordNode(string n)
        {
            type = "keyword";
            info = "";
            name = n;
        }
        KeywordNode(){
        }
};


class OperatorNode : public KeywordNode
{
    public:
        string name;
        string info;
        LLVMValueRef codegen();
        OperatorNode(string help, string n ){
            type = "operator";
            info = help;
            name = n;
        }
        OperatorNode(string n){
            type = "operator";
            info = "";
            name = n;
        }
};

class DataTypeNode: public ASTNode
{
    public:
        string info;
        string name;
        LLVMValueRef codegen();
        DataTypeNode(string help, string val)
        {
            type = "datatype";
            info = help;
            name = val;
        }
        DataTypeNode(string val)
        {
            type = "datatype";
            info = "";
            name = val;
        }
};

class IdNode : public ASTNode
{
    public:
        string name;
        LLVMValueRef codegen(bool load = true);
        IdNode(string n){
            type = "identifier";
            name = n;
        }
};


class DeclNode : public ASTNode{
    public:
        string dtype;
        string info;
        LLVMValueRef codegen();
        DeclNode(string d, string help){
            type = "decl_start";
            info = help;
            dtype = d;
        }
        DeclNode(string d){
            type = "decl_start";
            dtype = d;
            info = "";
        }
};


class ConstNode : public ASTNode{
    public:
        string category;
        LLVMValueRef codegen();
        union possible_value
        {
            int int_value;
            float float_value;
            char* string_value;
        };
        ConstNode::possible_value value;
        ConstNode(int i){
            type = "constant";
            category = "int";
            value.int_value = i;
        }

        ConstNode(float f){
            type = "constant";
            category = "float";
            value.float_value = f;
        }
        ConstNode(char* s){
            type = "constant";
            category = "string";
            value.string_value = s;
        }
        ConstNode(char s){
            type = "constant";
            category = "char";
            value.string_value = new char;
            value.string_value[0] = s;
        }
        ConstNode(){
        }
};

class FunctionNode : public ASTNode{
    public:
        string info;
        LLVMValueRef codegen(LLVMTypeRef return_type = LLVMVoidType());
        FunctionNode(string n)
        {
            type = "function";
            info = n;
        }
        FunctionNode()
        {
            type = "function";
            info = "";
        }
};
class ParamNode : public ASTNode{
    public:
        string info;
        string dtype;
        string name;
        LLVMValueRef codegen(LLVMValueRef function_header, int param_id, string fname);
        LLVMTypeRef codegen();
        ParamNode(string t, string n ){
            type = "param_info";
            name = n;
            dtype = t;
        }
        ParamNode(string n)
        {
            type = "param_info";
            info = n;
        }
        ParamNode()
        {
            type = "param_info";
            info = "";
        }
};


class PointerNode : public ASTNode{
    public:
        string info;
        int num_indirection;
        LLVMTypeRef codegen(LLVMTypeRef dtype);
        PointerNode(string n, int d){
            type = "pointer";
            info = n;
            num_indirection = d;
        }
        PointerNode(int d){
            type = "pointer";
            num_indirection = d;
            info = "";
        }
};
class BranchNode : public ASTNode{
    public:
        string name;
        string info;
        LLVMValueRef codegen();
        BranchNode(string help, string n){
            type = "control_flow";
            info = help;
            name = n;
        }
        BranchNode(string n){
            type = "control_flow";
            info = "";
            name = n;
        }

};

class BasicBlockNode : public ASTNode{
    public:
        string name;
        string info;
        LLVMValueRef codegen();
        BasicBlockNode(string help, string n){
            type = "jump_block";
            info = help;
            name = n;
        }
        BasicBlockNode(string n){
            type = "jump_block";
            info = "";
            name = n;
        }
};


class SymbolTable{
    public:
        //Symbol table used for program execution may use a tree like structure. But this symbol table is used to traverse the AST and create instructions. So stack is enough. 
        stack<map<string,LLVMValueRef>> table_stack;
        int size(){
            return table_stack.size();
        }
        void CreateScope(){
            map<string, LLVMValueRef> top;
            table_stack.push(top);
        }
        void DeleteScope(){
            table_stack.pop();
        }
        void InsertInScope(string key, LLVMValueRef value, int depth=0){
            if (depth == 0){
            table_stack.top()[key] = value;
            }
            else{
                map<string,LLVMValueRef>  currtop = table_stack.top();
                table_stack.pop();
                InsertInScope(key,value,depth-1);
                table_stack.push(currtop);
            }
        }
        bool IsNameInScope(string key, bool check_in_top_only = false){
            if (table_stack.empty())  return false;

            map<string,LLVMValueRef>  currtop = table_stack.top();
            if (currtop.find(key)!=currtop.end()){
                return true;
            }
            else{
                if (check_in_top_only){
                    return false;
                }
                table_stack.pop();
                bool isexist = IsNameInScope(key);
                table_stack.push(currtop);
                return isexist;
            }
        }
        LLVMValueRef ResolveName(string key){
            if (table_stack.empty()) return NULL;

            map<string,LLVMValueRef> currtop = table_stack.top();
            if (currtop.find(key)!=currtop.end()){
                return currtop[key];
            }
            else{
                table_stack.pop();
                LLVMValueRef ans = ResolveName(key);
                table_stack.push(currtop);
                return ans;
            }
        }
};


#endif

