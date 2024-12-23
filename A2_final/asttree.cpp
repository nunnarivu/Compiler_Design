/*
Author: Namasivayam K
Email: namasivayam.k@cse.iitd.ac.in
Last Modified: 14.11.2022
*/

/*Requirements: LLVM-9
    Debian package installation:
        wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
        sudo apt-add-repository "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-9.0 main"
        sudo apt-get update
        sudo apt-get install -y llvm-9 llvm-9-dev llvm-9-tools clang-9
*/

//Description: This file generates code from the AST build through bison and performs basic semantic analysis on the flow. 


//BASIC SEMANTIC ANALYSIS LIKE SCOPING AND DECLARATION CHECKING ARE HANDLED IN CODEGEN ITSELF. 
    /*POSSIBLE ERRORS
        1) DECL_ERROR: 
            a) Not declared before use.
            b) redlaration of variables in the current scope.
        2) FUNC_DEFN_ERROR:
            a) Redifining a function that is defined already. (Function overloading is not handled. can be added easily by modifing the symbol table)
        3) TYPE ERROR:
            a) Illegal types as operands for an operator.
    */


/*References:
    1) https://www.pauladamsmith.com/blog/2015/01/how-to-get-started-with-llvm-c-api.html
    2) https://llvm.org/doxygen/group__LLVMC.html
    3) https://github.com/skulltech-archive/compiler-design-assignment
    4)https://github.com/vaibhavbhagee/compiler-design/blob/master/Lab4/codeGeneration.cpp
*/


/*
Acknowledgement and Declaration:
    The author used (3) and (4) as the main references while writing this code. The core ideas are extracted from the references. 
    However, the implementation and its originality is entirely attributed to the author. 
*/

#include "asttree.hpp"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Verifier.h"


using namespace llvm;
using namespace std;

LLVMContextRef globalcontext;
LLVMModuleRef globalmodule;
LLVMBuilderRef globalbuilder;

SymbolTable SymTable;
LLVMTypeRef GetLLVMTypeFromString(string type, bool require_pointer);
LLVMValueRef FunctionCallCodeGen(ASTNode* tree);

LLVMTypeRef GetLLVMTypeFromString(string type, bool require_pointer = false){
    if (require_pointer){
        LLVMTypeRef t = GetLLVMTypeFromString(type, false);
        return LLVMPointerType(t, 0 );
    }
    if(type == "INT")
        return LLVMInt32Type();
    else if (type == "FLOAT")
        return LLVMFloatType();
    else if (type == "CHAR")
        return LLVMInt8Type();
    else if (type == "VOID")
        return LLVMVoidType();
    else if (type == "BOOL")
        return LLVMInt32Type();
    return NULL;
}

LLVMValueRef ASTNode::codegen(){
    if (this->type == "START" ){
        SymTable.CreateScope();
        for( auto child:this->children){
            child->codegen();
        }
        SymTable.DeleteScope();
    }
    else if (this->type == "SCOPE"){
        for(auto child:this->children){
            child->codegen();
        }
    }
    else if (this->type == "function"){
        return ((FunctionNode*)this)->codegen();
    }
    else if (this->type == "decl_start"){
        return ((DeclNode*)this)->codegen();
    }
    else if (this->type == "constant"){
        return ((ConstNode*)this)->codegen();
    }
    else if(this->type == "identifier"){
        return ((IdNode*)this)->codegen();
    }
    else if (this->type == "function_call"){
        return FunctionCallCodeGen(this);
    }
    else if (this->type == "operator"){
        return ((OperatorNode*)this)->codegen();
    }
    else if (this->type == "control_flow"){
        return ((BranchNode*)this)->codegen();
    }
    else if (this->type == "keyword"){
        return ((KeywordNode*)this)->codegen();
    }
    return NULL;
}



LLVMValueRef KeywordNode::codegen(){
    string key = this->name;
    if (key =="RETURN"){
        if (this->info == "return_void"){
            LLVMBuildRetVoid(globalbuilder);
        }
        else{
            LLVMBuildRet(globalbuilder, this->children[0]->codegen() );
        }
    }
    return NULL;
}


LLVMValueRef ConstNode::codegen(){
    if (this->category == "int"){
        return LLVMConstInt(GetLLVMTypeFromString("INT"), this->value.int_value, false);
    }
    else if (this->category == "float"){
        return LLVMConstReal(GetLLVMTypeFromString("FLOAT"), this->value.float_value);
    }
    else if (this->category == "string"){
        //code taken from reference (3). 
        string data = this->value.string_value;
        return LLVMBuildGlobalStringPtr(globalbuilder, data.c_str(), "string_constant");
        
    }
    else if (this->category == "char"){
        char *data = this->value.string_value;
        return LLVMConstIntOfStringAndSize(GetLLVMTypeFromString("CHAR"), data, 1, 16 );
    }
    else return NULL;
}
LLVMValueRef FunctionNode::codegen( LLVMTypeRef return_type){
    std::vector<LLVMTypeRef> paramtypes;
    bool isvaridic = false;
    string fname;
    ASTNode *body = NULL;
    ASTNode *parameters = NULL;
    
    for (auto child: this->children){
        string ctype = child->type;
        if (ctype == "identifier"){
            fname = ((IdNode*)child)->name;
        }
        else if (ctype == "SCOPE"){
                body = child;
            }   
        
        else if (ctype == "datatype"){
            if (((DataTypeNode*)child)->info == "type_spec"){
                return_type = GetLLVMTypeFromString(((DataTypeNode*)child)->name);
            }
           
        }
        else if (ctype == "identifier"){
            fname = (((IdNode*)child)->name);
        }
        else if (ctype == "parameters"){
            parameters = child;
            for (int i=0;i<child->children.size();i++){
                ASTNode *param = child->children[i];
                if (param->type == "param_info"){
                    paramtypes.push_back(((ParamNode*)param)->codegen());
                }
                else if (param->type == "keyword" && ((KeywordNode*)param)->name == "ELLIPSIS"){
                    isvaridic = true;
                }
            }
        }        
    }
    LLVMValueRef currfunc;
    LLVMTypeRef functype = LLVMFunctionType(return_type, paramtypes.data(), paramtypes.size(), isvaridic);
    //if name is already declared in scope, go for the definition.
    if (SymTable.IsNameInScope(fname)){
        currfunc = SymTable.ResolveName(fname);
        if (LLVMCountBasicBlocks(currfunc) > 0){
            cout<< "FUNC_DEFN_ERROR: Redefinition for "+fname+" found." <<endl;
            cout<< "NOTE: Function overloading not handled. Please use different function names"<<endl;
            exit(0);
        }
    }
    //else define the name and go for defn
    else{
        currfunc = LLVMAddFunction(globalmodule, fname.c_str(), functype);
        if (SymTable.IsNameInScope(fname,true) && body == NULL){
            cout <<"DECL ERROR: Redeclaration for " + fname + " found. Identifier" << fname +" already used in the current scope"<<endl;
             cout<< "NOTE: Function overloading not handled. Please use different function names if you are overloading functions"<<endl;
            exit(0);
        }
        SymTable.InsertInScope(fname,currfunc,0);
    }
    
    SymTable.CreateScope();
    if (body != NULL){
        LLVMBasicBlockRef entry = LLVMAppendBasicBlock(currfunc, "entry");
        LLVMPositionBuilderAtEnd(globalbuilder, entry);

         if (parameters !=NULL){
        for (int i=0; i<parameters->children.size();i++){
            ((ParamNode*)parameters->children[i])->codegen(currfunc,i, fname);
        }}

        for (auto instr: body->children){
                instr->codegen();
        }
    }
    SymTable.DeleteScope();
    return currfunc;
}


//Ackowledgement: The function BinaryExpCodegen is inspired from https://github.com/vaibhavbhagee/compiler-design/blob/master/Lab4/codeGeneration.cpp
LLVMValueRef BinaryExpCodegen(ASTNode* op1, ASTNode *op2, LLVMOpcode OpCode, bool bitwise = false){
    LLVMValueRef op1_val = op1->codegen();
    LLVMValueRef op2_val = op2->codegen();

    LLVMTypeKind op1_type = LLVMGetTypeKind(LLVMTypeOf(op1_val));
    LLVMTypeKind op2_type = LLVMGetTypeKind(LLVMTypeOf(op2_val));

    //Assumes the corresponding Opcode for Float type is next to int type. Need to relax this if signed and unsigned int is introduced. 
    if ((op1_type == LLVMFloatTypeKind || op2_type == LLVMFloatTypeKind) && (bitwise == false)){
        return LLVMBuildBinOp(globalbuilder, ((LLVMOpcode)(OpCode + 1)), op1_val, op2_val, "_flt_op");
    }
    else if (op1_type == LLVMPointerTypeKind && op2_type == LLVMIntegerTypeKind){
        LLVMValueRef indices = {op2_val};
        return LLVMBuildGEP(globalbuilder, op1_val, &indices, 1, "_ptr_add_int");
    }
    else{
        return LLVMBuildBinOp(globalbuilder, OpCode, op1_val, op2_val, "_int_op");
    }
}


LLVMValueRef OperatorNode::codegen(){
    string arg_detail = this->info;
    string op = this->name;
    if (arg_detail == "binary_op"){
        LLVMValueRef op1_val = this->children[0]->codegen();
        LLVMValueRef op2_val = this->children[1]->codegen();
        LLVMTypeKind op1_type = LLVMGetTypeKind(LLVMTypeOf(op1_val));
        LLVMTypeKind op2_type = LLVMGetTypeKind(LLVMTypeOf(op2_val));
            
        if (op == "ASSIGN"){
            ASTNode *lhs = this->children[0];
            if (lhs->type == "identifier"){
                LLVMValueRef lhs_val = ((IdNode*)lhs)->codegen(false);
                LLVMValueRef rhs_val = this->children[1]->codegen();
                return LLVMBuildStore(globalbuilder, rhs_val, lhs_val);
            }
            else if (lhs->type == "pointer"){
                LLVMValueRef lhs_val = ((IdNode*)lhs->children[0])->codegen(false);
                LLVMValueRef rhs_val = this->children[1]->codegen();
                return LLVMBuildStore(globalbuilder, rhs_val, lhs_val);
            }
         
        }
        else if (op == "ADD"){
            return BinaryExpCodegen(this->children[0], this->children[1], LLVMAdd);
        }
        else if (op == "MUL"){
            return BinaryExpCodegen(this->children[0], this->children[1], LLVMMul);
        }
        else if (op == "DIV"){
            return BinaryExpCodegen(this->children[0], this->children[1], LLVMSDiv);
        }
        else if (op == "SUB"){
            return BinaryExpCodegen(this->children[0], this->children[1], LLVMSub);
        }
        else if (op == "INT_MOD"){
            return BinaryExpCodegen(this->children[0], this->children[1], LLVMSRem);
        }
        else if (op == "LOGICAL_AND" || op == "&"){
            return 	LLVMBuildAnd(globalbuilder, op1_val, op2_val, "logical_and_");
        }   
        else if (op == "LOGICAL_OR" || op == "|"){
            return 	LLVMBuildOr(globalbuilder, op1_val, op2_val, "logical_or_");
        }
        else if (op == "LOGICAL_XOR" || op == "^"){
            return 	LLVMBuildXor(globalbuilder, op1_val, op2_val, "logical_xor_");
        }
        else if (op == "LEFT_SHIFT"){
            return LLVMBuildShl(globalbuilder, op1_val, op2_val, "shift_left_");              
        }
        else if (op == "RIGHT_SHIFT"){
            return LLVMBuildLShr(globalbuilder, op1_val, op2_val, "shift_right_"); 
        }
        else if (op == "EQ"){
            if ((op1_type == LLVMFloatTypeKind) && (op2_type == LLVMFloatTypeKind) ){
                return LLVMBuildFCmp(globalbuilder, LLVMRealOEQ, op1_val, op2_val, "_real_is_equal_");
            }
            else if   ((op1_type == LLVMIntegerTypeKind) && (op2_type == LLVMIntegerTypeKind) ){
                return LLVMBuildICmp(globalbuilder, LLVMIntEQ, op1_val, op2_val, "_int_is_eq_");
            }
            else{
                cout<< "TYPE_ERROR: Both operand should be of same type for == "<<endl;
                exit(0);
            }
        }
        else if (op == "NEQ"){
            if ((op1_type == LLVMFloatTypeKind) && (op2_type == LLVMFloatTypeKind) ){
                return LLVMBuildFCmp(globalbuilder, LLVMRealONE, op1_val, op2_val, "_real_not_equal_");
            }
            else if   ((op1_type == LLVMIntegerTypeKind) && (op2_type == LLVMIntegerTypeKind) ){
                return LLVMBuildICmp(globalbuilder, LLVMIntNE, op1_val, op2_val, "_int_not_eq_");
            }
            else{
                cout<< "TYPE_ERROR: Both operand should be of same type for != "<<endl;
                exit(0);
            }
        }
        else if (op == "LESS_THAN"){
            if ((op1_type == LLVMFloatTypeKind) && (op2_type == LLVMFloatTypeKind) ){
                return LLVMBuildFCmp(globalbuilder, LLVMRealOLT, op1_val, op2_val, "_real_less_than_");
            }
            else if   ((op1_type == LLVMIntegerTypeKind) && (op2_type == LLVMIntegerTypeKind) ){
                return LLVMBuildICmp(globalbuilder, LLVMIntSLT, op1_val, op2_val, "_int_less_than_");
            }
            else{
                cout<< "TYPE_ERROR: Both operand should be of same type for < "<<endl;
                exit(0);
            }
        }
        else if (op == "LESS_EQ"){
            if ((op1_type == LLVMFloatTypeKind) && (op2_type == LLVMFloatTypeKind) ){
                return LLVMBuildFCmp(globalbuilder, LLVMRealOLE, op1_val, op2_val, "_real_less_equal_");
            }
            else if   ((op1_type == LLVMIntegerTypeKind) && (op2_type == LLVMIntegerTypeKind) ){
                return LLVMBuildICmp(globalbuilder, LLVMIntSLE, op1_val, op2_val, "_int_less_equal_");
            }
            else{
                cout<< "TYPE_ERROR: Both operand should be of same type for <= "<<endl;
                exit(0);
            }
        }
        else if (op == "GREATER_THAN"){
            if ((op1_type == LLVMFloatTypeKind) && (op2_type == LLVMFloatTypeKind) ){
                return LLVMBuildFCmp(globalbuilder, LLVMRealOGT, op1_val, op2_val, "_real_greater_than_");
            }
            else if   ((op1_type == LLVMIntegerTypeKind) && (op2_type == LLVMIntegerTypeKind) ){
                return LLVMBuildICmp(globalbuilder, LLVMIntSGT, op1_val, op2_val, "_int_greater_than_");
            }
            else{
                cout<< "TYPE_ERROR: Both operand should be of same type for > "<<endl;
                exit(0);
            }
        }
        else if (op == "GREATER_EQ"){
              if ((op1_type == LLVMFloatTypeKind) && (op2_type == LLVMFloatTypeKind) ){
                return LLVMBuildFCmp(globalbuilder, LLVMRealOGE, op1_val, op2_val, "_real_greater_eq_");
            }
            else if   ((op1_type == LLVMIntegerTypeKind) && (op2_type == LLVMIntegerTypeKind) ){
                return LLVMBuildICmp(globalbuilder, LLVMIntSGE, op1_val, op2_val, "_int_greater_eq_");
            }
            else{
                cout<< "TYPE_ERROR: Both operand should be of same type for >= "<<endl;
                exit(0);
            }
        }
    }
    else if (arg_detail == "unary_op"){
        LLVMValueRef op1_val = this->children[0]->codegen();
        if (op == "POST_INCREMENT"){ 
            auto *temp = new ConstNode(1);
            LLVMValueRef op2_val = ((ConstNode*)temp)->codegen();
            LLVMValueRef inc = LLVMBuildAdd(globalbuilder, op1_val, op2_val, "_post_inc_");
            if (this->children[0]->type == "identifier"){
                 LLVMValueRef lhs_val = ((IdNode*)this->children[0])->codegen(false);
                LLVMBuildStore(globalbuilder, inc, lhs_val );
            }
            return op1_val; 
        }
        else if (op == "PRE_INCREMENT"){
            auto *temp = new ConstNode(1);
            LLVMValueRef op2_val = ((ConstNode*)temp)->codegen();
            LLVMValueRef inc =  LLVMBuildAdd(globalbuilder, op1_val, op2_val, "_pre_inc_");
             if (this->children[0]->type == "identifier"){
                 LLVMValueRef lhs_val = ((IdNode*)this->children[0])->codegen(false);
                 LLVMBuildStore(globalbuilder, inc, lhs_val );
            }
            return inc; 
        }
        else if (op == "PRE_DECREMENT"){
            auto *temp = new ConstNode(1);
            LLVMValueRef op2_val = ((ConstNode*)temp)->codegen();
            LLVMValueRef dec = LLVMBuildSub(globalbuilder, op1_val, op2_val, "_pre_dec_");
            if (this->children[0]->type == "identifier"){
                 LLVMValueRef lhs_val = ((IdNode*)this->children[0])->codegen(false);
                 LLVMBuildStore(globalbuilder, dec, lhs_val );
            }   
            return dec; 
        }
        else if (op == "POST_DECREMENT"){
            auto *temp = new ConstNode(1);
            LLVMValueRef op2_val = ((ConstNode*)temp)->codegen();
            LLVMValueRef dec = LLVMBuildSub(globalbuilder, op1_val, op2_val, "_post_dec_");
            if (this->children[0]->type == "identifier"){
                 LLVMValueRef lhs_val = ((IdNode*)this->children[0])->codegen(false);
                 LLVMBuildStore(globalbuilder, dec, lhs_val );
            }
            return op1_val; 
        }
        else if (op == "NOT" || op == "BITWISE_NOT"){
            return LLVMBuildNeg(globalbuilder, op1_val, "_bit_not_");
        }
        else if (op == "REFERENCE"){

        }
        else if (op == "DEREF"){

        }
    }
    else{
        return NULL;
    }
    return NULL;
}

LLVMTypeRef PointerNode::codegen(LLVMTypeRef dtype){
    LLVMTypeRef current_type = dtype;
    for (int i =0; i<this->num_indirection; i++){
        current_type = LLVMPointerType(current_type, 0);
    }
    return current_type;
}


LLVMValueRef ParamNode::codegen(LLVMValueRef function_header, int param_id, string fname){
    string dtype;
    for (auto child : this->children){
        if (child->type == "datatype"){
            dtype = ((DataTypeNode*)child)->name;
        }
        if (child->type == "identifier"){
            LLVMValueRef param =  LLVMGetParam(function_header, param_id);
            
            if (SymTable.IsNameInScope(fname,true)){
                cout << "DECL_ERROR: identifier for the parameter id " <<param_id << " is already used in this scope."<<endl;
                exit(0);
            }
            //allocate a dummy variable to load and modify the function parameters. 
            LLVMValueRef allocated = LLVMBuildAlloca(globalbuilder, GetLLVMTypeFromString(dtype),((IdNode*)child)->name.c_str() );
            SymTable.InsertInScope(((IdNode*)child)->name, allocated);
            LLVMBuildStore(globalbuilder, param, allocated);
            return allocated;
        }
        if (child->type == "pointer"){
            LLVMValueRef param =  LLVMGetParam(function_header, param_id);
            
            if (SymTable.IsNameInScope(fname,true)){
                cout << "DECL_ERROR: identifier for the parameter id " <<param_id << " is already used in this scope."<<endl;
                exit(0);
            }
            //allocate a dummy variable to load and modify the function parameters. 
            LLVMTypeRef pointer_type = ((PointerNode*)child)->codegen(GetLLVMTypeFromString(dtype));
            LLVMValueRef allocated = LLVMBuildAlloca(globalbuilder, pointer_type,((IdNode*)child->children[0])->name.c_str() );
            SymTable.InsertInScope(((IdNode*)child->children[0])->name, allocated);
            LLVMBuildStore(globalbuilder, param, allocated);
            return allocated;
        }
    }
    return NULL;
}

LLVMTypeRef ParamNode::codegen(){
    LLVMTypeRef param_type;
    for (auto child: this->children){
        if (child->type == "datatype"){
            param_type = GetLLVMTypeFromString(((DataTypeNode*)child)->name);
            break;
        }
    }
    for (auto child :  this->children){
        if (child->type == "pointer"){
            param_type = ((PointerNode*)child)->codegen(param_type);
        }
    }
    return param_type;
}

LLVMValueRef IdNode::codegen(bool load){
    if (SymTable.ResolveName(this->name) == NULL){
        cout << "DECL ERROR: No declaration for "+this->name+" in the current scope."<<endl;
        exit(0);
    }
    LLVMValueRef val = SymTable.ResolveName(this->name);
    if (load)
        return LLVMBuildLoad(globalbuilder, val, ("load_"+this->name).c_str());
    else
        return val;
}


void DeclareVariable(ASTNode *t, LLVMTypeRef decl_type){
    for (auto child: t->children){
        if (child->type == "identifier"){
            string varname = ((IdNode*)child)->name; 
            if (SymTable.IsNameInScope(varname,true)){
                cout << "DECL_ERROR: identifier " << varname << " is already used in this scope."<<endl;
                exit(0);
            }
            if (SymTable.size() == 1){
                LLVMValueRef allocated = LLVMAddGlobal(globalmodule, decl_type, varname.c_str());
                SymTable.InsertInScope(varname, allocated);
            }
            else{
                 LLVMValueRef allocated = LLVMBuildAlloca(globalbuilder, decl_type, varname.c_str());
                SymTable.InsertInScope(varname, allocated);
            }
        }
        if (child->type == "pointer"){
            DeclareVariable(child, decl_type);
        }
        else{
            child->codegen();
        }
    }
}

LLVMValueRef DeclNode::codegen(){
    LLVMTypeRef decl_type = GetLLVMTypeFromString(this->dtype);
    for (auto child: this->children){
        if (child->type == "decl_info"){
            if (child->children[0]->type =="func"){
                ((FunctionNode*)child->children[0])->codegen(decl_type);
            } 
            else if (child->children[0]->type == "identifier"){
               DeclareVariable(child, decl_type);
            }
            else if (child->children[0]->type == "pointer"){
                LLVMTypeRef pointer_type = ((PointerNode*)child->children[0])->codegen(decl_type);
                DeclareVariable(child, pointer_type);
            }
        }
    }
    return NULL;
}


LLVMValueRef FunctionCallCodeGen(ASTNode* tree){
    LLVMValueRef func;
    ASTNode *args = NULL;
    for (auto child: tree->children){
        if (child->type == "identifier"){
            func = ((IdNode*)child)->codegen(false);
        } 
        else if (child->type == "args"){
            args = child;
        }
    }
    if (args == NULL){
        LLVMValueRef *dummy;
        return LLVMBuildCall(globalbuilder, func, dummy, 0, "_func_call_");
    }
    else{
        vector<LLVMValueRef> argument_values;
        for (auto arg : args->children){
            argument_values.push_back(arg->codegen());
        }
        return LLVMBuildCall(globalbuilder, func, argument_values.data(), argument_values.size(), "_func_call_args_");
    }
    return NULL;
}


LLVMValueRef BranchNode::codegen(){
    LLVMBasicBlockRef curr_block = LLVMGetInsertBlock(globalbuilder);
    LLVMValueRef parent_func = LLVMGetBasicBlockParent(curr_block);

    string branch_type = this->name;
    if (branch_type == "IF"){
        LLVMBasicBlockRef true_block = LLVMAppendBasicBlock(parent_func, "true_block");
        LLVMBasicBlockRef after_end_block = LLVMAppendBasicBlock(parent_func, "endif");
        for (auto child : this->children){
            string category = ((BasicBlockNode*)child)->name;
            if (category == "condition"){
                LLVMPositionBuilderAtEnd(globalbuilder, curr_block);
                LLVMValueRef cond = child->children[0]->codegen();
                LLVMBuildCondBr(globalbuilder, cond, true_block, after_end_block);
            }
            else if (category == "true_block"){
                LLVMPositionBuilderAtEnd(globalbuilder, true_block);
                SymTable.CreateScope();
                child->children[0]->codegen();
                LLVMBuildBr(globalbuilder, after_end_block);
                SymTable.DeleteScope();
            }
        }
        LLVMPositionBuilderAtEnd(globalbuilder, after_end_block);
        
    }
    else if (branch_type == "IF_ELSE"){
        LLVMBasicBlockRef true_block = LLVMAppendBasicBlock(parent_func, "true_block");
        LLVMBasicBlockRef false_block = LLVMAppendBasicBlock(parent_func, "false_block");
        LLVMBasicBlockRef after_end_block = LLVMAppendBasicBlock(parent_func, "endif");
        LLVMValueRef true_return, false_return;
        for (auto child : this->children){
            string category = ((BasicBlockNode*)child)->name;
            if (category == "condition"){
                LLVMPositionBuilderAtEnd(globalbuilder, curr_block);
                LLVMValueRef cond = child->children[0]->codegen();
                LLVMBuildCondBr(globalbuilder, cond, true_block, false_block);
            }
            else if (category == "true_block"){
                SymTable.CreateScope();
                LLVMPositionBuilderAtEnd(globalbuilder, true_block);
                true_return = child->children[0]->codegen();
                LLVMBuildBr(globalbuilder, after_end_block);
                SymTable.DeleteScope();
            }
            else if (category == "false_block"){
                SymTable.CreateScope();
                LLVMPositionBuilderAtEnd(globalbuilder, false_block);
                false_return = child->children[0]->codegen();
                LLVMBuildBr(globalbuilder, after_end_block);
                SymTable.DeleteScope();
            }
        }
        LLVMPositionBuilderAtEnd(globalbuilder, after_end_block);
    }
    else if (branch_type == "WHILE"){
        LLVMBasicBlockRef cond_block = LLVMAppendBasicBlock(parent_func, "cond");
        LLVMBasicBlockRef true_block = LLVMAppendBasicBlock(parent_func, "true_block");
        LLVMBasicBlockRef after_end_block = LLVMAppendBasicBlock(parent_func, "endwhile");
        LLVMValueRef true_return, false_return;
        LLVMBuildBr(globalbuilder, cond_block);
        for (auto child : this->children){
            string category = ((BasicBlockNode*)child)->name;
            if (category == "condition"){
                LLVMPositionBuilderAtEnd(globalbuilder, cond_block);
                LLVMValueRef cond = child->children[0]->codegen();
                LLVMBuildCondBr(globalbuilder, cond, true_block, after_end_block);
            }
            else if (category == "true_block"){
                SymTable.CreateScope();
                LLVMPositionBuilderAtEnd(globalbuilder, true_block);
                true_return = child->children[0]->codegen();
                LLVMBuildBr(globalbuilder, cond_block);
                SymTable.DeleteScope();
            }
        }
        LLVMPositionBuilderAtEnd(globalbuilder, after_end_block);
    }
    else if (branch_type == "DO_WHILE"){
        LLVMBasicBlockRef cond_block = LLVMAppendBasicBlock(parent_func, "cond");
        LLVMBasicBlockRef true_block = LLVMAppendBasicBlock(parent_func, "true_block");
        LLVMBasicBlockRef after_end_block = LLVMAppendBasicBlock(parent_func, "endwhile");
        LLVMValueRef true_return, false_return;
        LLVMBuildBr(globalbuilder, true_block);
        for (auto child : this->children){
            string category = ((BasicBlockNode*)child)->name;
            if (category == "condition"){
                LLVMPositionBuilderAtEnd(globalbuilder, cond_block);
                LLVMValueRef cond = child->children[0]->codegen();
                LLVMBuildCondBr(globalbuilder, cond, true_block, after_end_block);
            }
            else if (category == "true_block"){
                SymTable.CreateScope();
                LLVMPositionBuilderAtEnd(globalbuilder, true_block);
                true_return = child->children[0]->codegen();
                LLVMBuildBr(globalbuilder, cond_block);
                SymTable.DeleteScope();
            }
        }
        LLVMPositionBuilderAtEnd(globalbuilder, after_end_block);
    }
    return NULL;
    }
    

void codegeneration(ASTNode *tree){
    globalcontext = LLVMGetGlobalContext();
    globalbuilder = LLVMCreateBuilderInContext(globalcontext);
    globalmodule = LLVMModuleCreateWithNameInContext("main_module", globalcontext);

    tree->codegen();
    cout<<"codegen_completed"<<endl;
    
    cout<<endl;

    // printf("%s", LLVMPrintModuleToString(globalmodule));
    FILE *f = fopen("codegen.txt", "w");
    fprintf(f, "%s",LLVMPrintModuleToString(globalmodule));
    
    // LLVMDisposeBuilder(globalbuilder);
    // LLVMContextDispose(globalcontext);
    
}

