#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "c.tab.hpp"
#include "asttree.hpp"


extern "C" ASTNode *ASTtree;
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
static void usage()
{
  printf("Usage: cc <prog.c>\n");
}
using namespace std;

// int
// main(int argc, char **argv)
// {
//   if (argc != 2) {
//     usage();
//     exit(1);
//   }
//   char const *filename = argv[1];
//   yyin = fopen(filename, "r");
//   assert(yyin);
//   int ret = yyparse();
//   printf("retv = %d\n", ret);
//   exit(0);
// }


char depth[2056];
int di;
void printTree(ASTNode* tree) {
  if (tree == NULL) {return;}

  if (tree->type == "constant") {
    string category = ((ConstNode*)tree)->category;
    if (category == "int"){
      cout << ((ConstNode*)tree)->value.int_value << " (int) "<< std::endl;
    }
    else if (category == "float") {
      cout << ((ConstNode*)tree)->value.float_value << " (float) "<< std::endl;
    }
    else if (category == "char"){
      cout << ((ConstNode*)tree)->value.string_value << " (char) "<< std::endl;
    }
    else {
      cout << ((ConstNode*)tree)->value.string_value << " (char*) " << std::endl;
    }
  }  
  else if (tree->type == "pointer"){
    cout << "pointer (num_indirection = " << ((PointerNode*)tree)->num_indirection <<")" <<endl;
  }
  else if (tree->type == "operator")
  {
    cout << ((OperatorNode*)tree)->name<<endl;
  }
  else if (tree->type == "keyword"){
    cout << ((KeywordNode*)tree)->name<<endl;
  }
  else if (tree->type == "control_flow"){
    cout << ((BranchNode*)tree)->name << endl;
  }
  else if (tree->type == "jump_block"){
    cout << ((BasicBlockNode*)tree)->name <<endl;
  }
  else if (tree->type == "identifier"){
    cout << ((IdNode*)tree)->name <<endl;
  }
  else if (tree->type == "datatype"){
    cout << ((DataTypeNode*)tree)->name <<endl;
  }
  else{
    std::cout << tree->type << std::endl;
  }

  for (int i = 0; i < tree->children.size(); i++) {
    std::cout << depth << "  --";

    // push
    depth[di++] = ' ';
    depth[di++] = (i < tree->children.size() - 1)?'|':' ';
    depth[di++] = ' ';
    depth[di++] = ' ';
    depth[di] = 0;

    printTree(tree->children[i]);

    //pop
    depth[di -= 4] = 0;
  }
}

int
main(int argc, char **argv)
{
  if (argc != 2) {
    usage();
    exit(1);
  }
  char const *filename = argv[1];
  yyin = fopen(filename, "r");
  assert(yyin);

  // Parsing and AST generation
  int ret_val = yyparse();
  printTree(ASTtree);

  // Semantic analysis to ensure a) Declaration before use and b) Type checking
  // ret_val = semanticCheck(ASTree);
  std::cout << "retv = " << !ret_val << std::endl;

  codegeneration(ASTtree);

  exit(0);
}