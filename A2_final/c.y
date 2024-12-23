%code requires {
	#include <iostream>
	#include "asttree.hpp"
}

%{
#include <cstdio>
#include <iostream>
using namespace std;
#include "asttree.hpp"
// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
void yyerror(const char *s);

ASTNode *ASTtree = NULL;
%}


%union{
	ASTNode* node;
	int ival;
	float fval;
	char* sval;
	char cval;
}

%token <cval> CHAR_CONSTANT
%token	<sval>IDENTIFIER  STRING_LITERAL
%token  <ival> I_CONSTANT
%token  <fval> F_CONSTANT 
%token FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL


%type <node> start translation_unit external_declaration function_definition declaration  declarator direct_declarator init_declarator init_declarator_list initializer
%type <node> declaration_specifiers type_specifier compound_statement block_item parameter_type_list parameter_list parameter_declaration storage_class_specifier
%type <node> block_item_list statement labeled_statement jump_statement expression_statement selection_statement iteration_statement 
%type <node> assignment_expression   postfix_expression  constant_expression conditional_expression primary_expression  expression unary_expression multiplicative_expression additive_expression logical_and_expression shift_expression relational_expression equality_expression and_expression logical_or_expression exclusive_or_expression inclusive_or_expression 
%type <node> unary_operator assignment_operator
%type <node> constant string 
%type <node> identifier_list argument_expression_list pointer type_qualifier function_specifier





%start start
%%

start 
	: 
	translation_unit  {ASTNode *temp = new ASTNode("START");  temp->children = $1->children; $$=temp; ASTtree = $$;}
	;

translation_unit
	: external_declaration                        {ASTNode *temp = new ASTNode(""); temp->children.push_back($1); $$=temp;}
	| translation_unit external_declaration       {ASTNode *temp = new ASTNode("");
														for(int i=0; i<$1->children.size(); i++)
														{
															temp->children.push_back($1->children[i]);
														}
														temp->children.push_back($2);
														$$ = temp;
												   }
	;

external_declaration
	: function_definition						{$$=$1;}
	| declaration								{$$=$1;}
	;


function_definition
	: declaration_specifiers declarator declaration_list compound_statement    {$$ = $2;}
	| declaration_specifiers declarator compound_statement               		{auto *fun = new FunctionNode(""); 
																			  	fun->children = $1->children;
																				if ($2->type == "dummy" || "func"){
																				for (int i=0; i< $2->children.size(); i++){
																					fun->children.push_back($2->children[i]);
																				}}
																				else{
																				fun->children.push_back($2);}
																				fun->children.push_back($3);
																			  	$$ = fun;}     
	;


declaration_list
	: declaration															
	| declaration_list declaration											
	;

declaration
	: declaration_specifiers ';'											 {	string dtype;
																				for (auto child: $1->children){
																				if (child->type == "datatype"){
																					dtype = ((DataTypeNode*)child)->name;
																					break;
																				}
																				}
																				DeclNode *temp = new DeclNode(dtype);
																				temp->children = $1->children; $$=temp;
																			 }
	| declaration_specifiers init_declarator_list ';'						 {	string dtype;
																				for (auto child: $1->children){
																				if (child->type == "datatype"){
																					dtype = ((DataTypeNode*)child)->name;
																					break;
																				}
																				}
																				DeclNode *temp = new DeclNode(dtype);
																				temp->children = $1->children;
																				for (int i=0; i<$2->children.size(); i++){
																					temp->children.push_back($2->children[i]);
																				}
																				$$=temp; 
																				}
	;

declaration_specifiers
	: type_specifier declaration_specifiers									{auto *temp =  new ASTNode("dummy"); temp->children.push_back($1); 
																			for (int i = 0; i<$2->children.size();i++){
																				temp->children.push_back($2->children[i]);
																			}
																			$$ = temp;}
	
	| type_specifier														{auto *temp = new ASTNode("dummy"); temp->children.push_back($1); $$ = temp;}
	
	| type_qualifier declaration_specifiers									{auto *temp =  new ASTNode("dummy"); temp->children.push_back($1); 
																			for (int i = 0; i<$2->children.size();i++){
																				temp->children.push_back($2->children[i]);
																			}
																			$$ = temp;}
	
	| type_qualifier														{auto *temp = new ASTNode("dummy"); temp->children.push_back($1); $$ = temp;}
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier															
	;


init_declarator_list
	: init_declarator                              				 {auto *temp = new ASTNode("dummy"); temp->children.push_back($1); $$ = temp; }
	| init_declarator_list ',' init_declarator					  {ASTNode *temp = new ASTNode("dummy");
																	for (int i=0; i<$1->children.size(); i++){
																		temp->children.push_back($1->children[i]);
																	}
																	temp->children.push_back($3);
																	$$=temp;}
	;

init_declarator
	: declarator '=' initializer								{auto *temp = new ASTNode("decl_info"); temp->children.push_back($1);
																 OperatorNode* init = new OperatorNode("binary_op","ASSIGN"); 
																 init->children.push_back($1);
																 init->children.push_back($3);
																 temp->children.push_back(init);
																 $$ = temp;}
	| declarator                         						{auto *temp = new ASTNode("decl_info"); temp->children.push_back($1); $$ = temp;}
	;

declarator
	: pointer direct_declarator										{ $1->children.push_back($2);
																	// int depth = ((PointerNode*)$1)->num_indirection;
																	// ASTNode* temp = $1;
																	// for (int i=1;i<depth;i++){
																	// 	temp = temp->children[0];
																	// }
																	// temp->children.push_back($2);
																	$$ = $1;}

	| direct_declarator                                   			{$$=$1;}

	;

direct_declarator
	: IDENTIFIER                                {ASTNode *temp = new IdNode($1); $$ = temp;}
	| '(' declarator ')'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'              {ASTNode *temp = new ASTNode("func");
																   temp->children.push_back($1);
																   temp->children.push_back($3);
																   $$ = temp;}
	| direct_declarator '(' ')'									  {auto *temp = new ASTNode("func"); temp->children.push_back($1); $$=temp; }

// //function declared without types. ILLEGAL grammar!
// | direct_declarator '(' identifier_list ')'                   {auto *temp =new  ASTNode("function_declared_without_types"); temp->children.push_back($1); 
// 															  auto *args = new ASTNode("arguments");
// 															  if ($3->type == "dummy")
// 															  	args->children = $3->children;
// 															else
// 																args->children.push_back($3);
// 															temp->children.push_back(args);
// 															$$=temp;} 
	;

pointer
	: '*' pointer		{auto *temp = new PointerNode(((PointerNode*)$2)->num_indirection + 1);  $$ = temp;}
	| '*'				{auto *temp = new PointerNode(1); $$=temp; }
	;

type_specifier
	: VOID              {DataTypeNode *kwrd = new DataTypeNode("type_spec","VOID"); $$ = kwrd; }
	| CHAR				{DataTypeNode *kwrd = new DataTypeNode("type_spec","CHAR"); $$ = kwrd; }
	| INT				{DataTypeNode *kwrd = new DataTypeNode("type_spec","INT"); $$ = kwrd; }
	| FLOAT				{DataTypeNode *kwrd = new DataTypeNode("type_spec","FLOAT"); $$ = kwrd; }
	| BOOL				{DataTypeNode *kwrd = new DataTypeNode("type_spec","BOOL"); $$ = kwrd; }
	;

initializer
	: '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression                {$$ = $1;}
	;

initializer_list
	: designation initializer
	| initializer                                       
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	;

parameter_type_list
	: parameter_list ',' ELLIPSIS      {ASTNode *temp = new ASTNode("parameters");
										temp->children = $1->children;
										temp->children.push_back(new KeywordNode("ELLIPSIS"));
										$$ = temp;
										}
	| parameter_list					{ASTNode *temp = new ASTNode("parameters");
										 temp->children = $1->children;
										 $$ = temp;}
	;

parameter_list
	: parameter_declaration						{ASTNode *temp = new ASTNode("dummy"); temp->children.push_back($1); $$ = temp;}
	| parameter_list ',' parameter_declaration  {ASTNode *temp = new ASTNode("dummy");
												 for (int i=0; i<$1->children.size(); i++){
													temp->children.push_back($1->children[i]);
												 }
												 temp->children.push_back($3);
												 $$=temp;}
	;

parameter_declaration
	: declaration_specifiers declarator        {auto *temp = new ParamNode("param_with_id");
												temp->children = $1->children;
												temp->children.push_back($2);
												$$ =temp;}
	| declaration_specifiers				{auto *temp = new ParamNode("param_type_only"); temp->children = $1->children; $$ = temp;}
	;



block_item_list
	: block_item 						{auto *temp = new ASTNode("dummy"); temp->children.push_back($1); $$ = temp;}
	| block_item_list block_item		{ASTNode *temp = new ASTNode("dummy");
										for(int i=0; i<$1->children.size();i++){
											temp->children.push_back($1->children[i]);
										}
										temp->children.push_back($2);
										$$ = temp;}
	;

block_item
	: declaration                       {$$ = $1;}
	| statement							{$$ = $1;}
	;

statement
	: labeled_statement					{$$ = $1;}
	| compound_statement				{$$ = $1;}
	| expression_statement				{$$ = $1;}
	| selection_statement				{$$ = $1;}
	| iteration_statement				{$$ = $1;}
	| jump_statement					{$$ = $1;}
	;

compound_statement
	: '{' '}'																	{ASTNode *temp = new ASTNode("SCOPE"); $$ = temp;}
	| '{'  block_item_list '}'													{ASTNode *temp = new ASTNode("SCOPE"); 
																				if ($2->type == "dummy"){
																					for (int i=0;i<$2->children.size();i++){
																						temp->children.push_back($2->children[i]);}
																				}
																				else
																					temp->children.push_back($2);
																				$$ = temp;
																				 }
	;


labeled_statement
	: IDENTIFIER ':' statement									{auto *temp = new BranchNode("LABEL"); 
																auto *id = new IdNode($1);
																temp->children.push_back((ASTNode*)id);	
																temp->children.push_back($3);
																$$ = temp; }
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

expression_statement
	: ';'															{ASTNode *temp = new ASTNode(";"); $$=temp;}
	| expression ';'												{$$=$1;}
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement              {auto *temp = new BranchNode("IF_ELSE"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back($3);
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back($5);
																	auto *elsepart = new BasicBlockNode("false_block");
																	elsepart->children.push_back($7);
																	temp->children.push_back(cond);
																	temp->children.push_back(ifpart);
																	temp->children.push_back(elsepart);
																	$$ = temp;
																	}

	| IF '(' expression ')' statement								{auto *temp = new BranchNode("IF"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back($3);
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back($5);
																	temp->children.push_back(cond);
																	temp->children.push_back(ifpart);
																	$$ = temp;
																	}

	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement							{auto *temp = new BranchNode("WHILE"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back($3);
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back($5);
																	temp->children.push_back(cond);
																	temp->children.push_back(ifpart);
																	$$ = temp;

																	}

	| DO statement WHILE '(' expression ')' ';'						{auto *temp = new BranchNode("DO_WHILE"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back($5);
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back($2);
																	temp->children.push_back(ifpart);
																	temp->children.push_back(cond);
																	$$ = temp;
																	}

	| FOR '(' expression_statement expression_statement ')' statement 										{auto *temp = new BranchNode("FOR"); 
																											auto *cond = new BasicBlockNode("condition");
																											auto *decl = new BasicBlockNode("initial");
																											cond->children.push_back($4);
																											if ($3->type != ";"){
																												decl->children.push_back($3);
																												temp->children.push_back(decl);
																												temp->children.push_back(cond);
																											}
																											else{
																												temp->children.push_back(cond);
																											}
																											auto *ifpart = new BasicBlockNode("true_block");
																											ifpart->children.push_back($6);
																											temp->children.push_back(ifpart);
																											$$ = temp;
																											}

	| FOR '(' expression_statement expression_statement expression ')' statement   			{auto *temp = new BranchNode("FOR"); 
																							auto *cond = new BasicBlockNode("condition");
																							auto *decl = new BasicBlockNode("initial");
																							auto *incr = new BasicBlockNode("increment");
																							cond->children.push_back($4);
																							incr->children.push_back($5);
																							if ($3->type != ";"){
																								decl->children.push_back($3);
																								temp->children.push_back(decl);
																							}
																							temp->children.push_back(cond);
																							temp->children.push_back(incr);
																							auto *ifpart = new BasicBlockNode("true_block");
																							ifpart->children.push_back($7);
																							temp->children.push_back(ifpart);
																							$$ = temp;
																							}

	| FOR '(' declaration expression_statement ')' statement							    {auto *temp = new BranchNode("FOR"); 
																							auto *cond = new BasicBlockNode("condition");
																							auto *decl = new BasicBlockNode("initial");
																							cond->children.push_back($4);
																							decl->children.push_back($3);
																							temp->children.push_back(decl);
																							temp->children.push_back(cond);
																							auto *ifpart = new BasicBlockNode("true_block");
																							ifpart->children.push_back($6);
																							temp->children.push_back(ifpart);
																							$$ = temp;
																							}


	| FOR '(' declaration expression_statement expression ')' statement						{auto *temp = new BranchNode("FOR"); 
																							auto *cond = new BasicBlockNode("condition");
																							auto *decl = new BasicBlockNode("initial");
																							auto *incr = new BasicBlockNode("increment");
																							cond->children.push_back($4);
																							incr->children.push_back($5);
																							decl->children.push_back($3);
																							temp->children.push_back(decl);
																							temp->children.push_back(cond);
																							temp->children.push_back(incr);
																							auto *ifpart = new BasicBlockNode("true_block");
																							ifpart->children.push_back($7);
																							temp->children.push_back(ifpart);
																							$$ = temp;
																							}
	;

jump_statement
	: GOTO IDENTIFIER ';'									{auto *temp = new BranchNode("GOTO"); 
															auto *id = new IdNode($2);
															temp->children.push_back((ASTNode*)id);
															$$ = temp;}
	| CONTINUE ';'											{auto *temp = new BranchNode("CONTINUE"); $$=temp;}
	| BREAK ';'												{auto *temp = new BranchNode("BREAK"); $$=temp;}
	| RETURN ';'											{auto *temp = new KeywordNode("return_void", "RETURN"); $$=temp;}
	| RETURN expression ';'									{KeywordNode *temp = new KeywordNode("return_value", "RETURN"); temp->children.push_back($2); $$=temp;}
	;

expression
	: assignment_expression									{$$=$1;}
	| expression ',' assignment_expression				    {auto *temp = new ASTNode("expr"); 
															temp->children = $1->children;
															temp->children.push_back($3);
															$$ = temp;}
	;

constant_expression
	: conditional_expression	/* with constraints */       {$$=$1;}
	;

primary_expression
	: IDENTIFIER											{ASTNode *temp = new IdNode($1); $$ = temp;}
	| constant												{$$=$1;}
	| string												{$$=$1;}
	| '(' expression ')'									{$$=$2;}
	;

constant
	: I_CONSTANT		/* includes character_constant */ {ConstNode *con = new ConstNode($1);  $$=con;}
	| F_CONSTANT										  {ConstNode *con = new ConstNode($1); $$=con;}
	| CHAR_CONSTANT										  {ConstNode *con = new ConstNode($1); $$ = con;}
	;

string
	: STRING_LITERAL										{ConstNode *con = new ConstNode($1); $$=con;}
	| FUNC_NAME
	;

postfix_expression
	: primary_expression									{$$=$1;}
	| postfix_expression '[' expression ']'				
	| postfix_expression '(' ')'							{auto *temp = new ASTNode("function_call"); temp->children.push_back($1); $$=temp;}
	| postfix_expression '(' argument_expression_list ')'  	{auto *temp = new ASTNode("function_call"); temp->children.push_back($1), temp->children.push_back($3); $$= temp;}
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP								{OperatorNode *uop = new OperatorNode("unary_op", "POST_INCREMENT"); uop->children.push_back($1); $$=uop;}	
	| postfix_expression DEC_OP								{OperatorNode *uop = new OperatorNode("unary_op", "POST_DECREMENT"); uop->children.push_back($1); $$=uop;}
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression									{ASTNode *temp = new ASTNode("args"); temp->children.push_back($1); $$ = temp;}
	| argument_expression_list ',' assignment_expression	{
																ASTNode *temp = new ASTNode("args"); 
																for (int i = 0; i<$1->children.size(); i++)
																{
																	temp->children.push_back($1->children[i]);
																}
																temp->children.push_back($3); 
																$$ = temp;
															}
	;

unary_expression
	: postfix_expression									{$$=$1;}
	| INC_OP unary_expression								{OperatorNode *uop = new OperatorNode("unary_op", "PRE_INCREMENT"); uop->children.push_back($2); $$=uop;}
	| DEC_OP unary_expression								{OperatorNode *uop = new OperatorNode("unary_op", "PRE_DECREMENT"); uop->children.push_back($2); $$=uop;}
	| unary_operator unary_expression						{$1->children.push_back($2); $$ = $1;}
	;

unary_operator
	: '&'														{OperatorNode *op = new OperatorNode("unary_op", "REFERENCE"); $$=op;}
	| '*'														{OperatorNode *op = new OperatorNode("unary_op", "DEREF"); $$=op;}
	| '+'														{OperatorNode *op = new OperatorNode("unary_op", "UNARY_PLUS"); $$=op;}
	| '-'														{OperatorNode *op = new OperatorNode("unary_op", "UNARY_NEG"); $$=op;}
	| '~'														{OperatorNode *op = new OperatorNode("unary_op", "BITWISE_NOT"); $$=op;}
	| '!'														{OperatorNode *op = new OperatorNode("unary_op", "NOT"); $$=op;}
	;

multiplicative_expression
	: unary_expression												{$$=$1;}
	| multiplicative_expression '*' unary_expression					{OperatorNode *op = new OperatorNode("binary_op", "MUL");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| multiplicative_expression '/' unary_expression					{OperatorNode *op = new OperatorNode("binary_op", "DIV");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| multiplicative_expression '%' unary_expression					{OperatorNode *op = new OperatorNode("binary_op", "INT_MOD");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

additive_expression
	: multiplicative_expression										{$$=$1;}
	| additive_expression '+' multiplicative_expression				{OperatorNode *op = new OperatorNode("binary_op", "ADD");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| additive_expression '-' multiplicative_expression				{OperatorNode *op = new OperatorNode("binary_op", "SUB");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

shift_expression
	: additive_expression											{$$=$1;}
	| shift_expression LEFT_OP additive_expression					{OperatorNode *op = new OperatorNode("binary_op", "LEFT_SHIFT");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| shift_expression RIGHT_OP additive_expression					{OperatorNode *op = new OperatorNode("binary_op", "RIGHT_SHIFT");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

relational_expression
	: shift_expression												{$$=$1;}
	| relational_expression '<' shift_expression					{OperatorNode *op = new OperatorNode("binary_op", "LESS_THAN");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| relational_expression '>' shift_expression					{OperatorNode *op = new OperatorNode("binary_op", "GREATER_THAN");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| relational_expression LE_OP shift_expression					{OperatorNode *op = new OperatorNode("binary_op", "LESS_EQ");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	| relational_expression GE_OP shift_expression					{OperatorNode *op = new OperatorNode("binary_op", "GREATER_EQ");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

equality_expression
	: relational_expression											{$$=$1;}
	| equality_expression EQ_OP relational_expression				{OperatorNode *op = new OperatorNode("binary_op", "EQ");
																	op->children.push_back($1);			
																	op->children.push_back($3);
																	$$=op;
																	}
	| equality_expression NE_OP relational_expression				{OperatorNode *op = new OperatorNode("binary_op", "NEQ");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

and_expression
	: equality_expression											{$$=$1;}
	| and_expression '&' equality_expression						{OperatorNode *op = new OperatorNode("binary_op", "&");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

exclusive_or_expression
	: and_expression												{$$=$1;}
	| exclusive_or_expression '^' and_expression					{OperatorNode *op = new OperatorNode("binary_op", "^");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

inclusive_or_expression
	: exclusive_or_expression										{$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression			{OperatorNode *op = new OperatorNode("binary_op", "|");
																	op->children.push_back($1);
																	op->children.push_back($3);
																	$$=op;
																	}
	;

logical_and_expression
	: inclusive_or_expression								       {$$=$1;}
	| logical_and_expression AND_OP inclusive_or_expression  		{OperatorNode *temp = new OperatorNode("binary_op","LOGICAL_AND");
																	temp->children.push_back($1);
																	temp->children.push_back($3);
																	$$=temp;}
	;

logical_or_expression
	: logical_and_expression								{$$=$1;}
	| logical_or_expression OR_OP logical_and_expression	{OperatorNode *temp = new OperatorNode("binary_op","LOGICAL_OR");
															temp->children.push_back($1);
															temp->children.push_back($3);
															$$=temp;}
	;

conditional_expression
	: logical_or_expression													{$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression		{OperatorNode *temp = new OperatorNode("ternary_op", "CONDITIONAL"); 
																			temp->children.push_back($1);
																			temp->children.push_back($3);
																			temp->children.push_back($5);
																			$$ = temp;}
	;

assignment_expression
	: conditional_expression                                           {$$=$1;}
	| unary_expression assignment_operator assignment_expression		{$2->children.push_back($1); $2->children.push_back($3); $$=$2;}
	;

assignment_operator
	: '='							{OperatorNode *temp = new OperatorNode("binary_op","ASSIGN"); $$ = temp; }
	| MUL_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","MUL_ASSIGN"); $$ = temp; }
	| DIV_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","DIV_ASSIGN"); $$ = temp; }
	| MOD_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","MOD_ASSIGN"); $$ = temp; }
	| ADD_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","ADD_ASSIGN"); $$ = temp; }
	| SUB_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","SUB_ASSIGN"); $$ = temp; }
	| LEFT_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","LEFT_ASSIGN"); $$ = temp; }
	| RIGHT_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","RIGHT_ASSIGN"); $$ = temp; }
	| AND_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","AND_ASSIGN"); $$ = temp; }
	| XOR_ASSIGN					{OperatorNode *temp = new OperatorNode("binary_op","XOR_ASSIGN"); $$ = temp; }
	| OR_ASSIGN						{OperatorNode *temp = new OperatorNode("binary_op","OR_ASSIGN"); $$ = temp; }
	;


storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */ 
	| EXTERN						{KeywordNode *temp = new KeywordNode("storage_spec", "EXTERN"); $$=temp;}
	| STATIC						{KeywordNode *temp = new KeywordNode("storage_spec", "STATIC"); $$=temp;}
	| AUTO							{KeywordNode *temp = new KeywordNode("storage_spec", "AUTO"); $$=temp;}
	;


specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;


atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;


alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

identifier_list
	: IDENTIFIER							{ASTNode *temp = new ASTNode("dummy");
											auto *id = new IdNode($1);
											temp->children.push_back((ASTNode*)id); $$ = temp;}
	| identifier_list ',' IDENTIFIER		{auto *temp = new ASTNode("dummy");
											for (int i=0; i<$1->children.size(); i++){
												temp->children.push_back($1->children[i]);
											}
											auto *id = new IdNode($3);
											temp->children.push_back((ASTNode*)id);
											$$=temp;}
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;


designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	;


type_qualifier
	: CONST            {auto *temp = new KeywordNode("type_qualifier", "CONST"); $$ = temp;}
	| RESTRICT			{auto *temp = new KeywordNode("type_qualifier", "RESTRICT"); $$ = temp;}
	| VOLATILE			{auto *temp = new KeywordNode("type_qualifier", "VOLATILE"); $$ = temp;}
	| ATOMIC			{auto *temp = new KeywordNode("type_qualifier", "ATOMIC"); $$ = temp;}
	;

function_specifier
	: INLINE			{auto *temp = new KeywordNode("func_spec", "INLINE"); $$ = temp;}
	| NORETURN			{auto *temp = new KeywordNode("func_spec", "NORETURN"); $$ = temp;}
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;



%%
#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
