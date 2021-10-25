%{
#include <stdio.h>
#include <vector>
#include "tree/common.h"
#include "symbol.h"
#include "scope.h"
#include "tree/node.h"
#include "tree/programnode.h"
#include "tree/vardeclarationnode.h"
#include "tree/vectordeclarationnode.h"
#include "tree/headernode.h"
#include "tree/functiondefinitionnode.h"
#include "tree/assignmentnode.h"
#include "tree/inputnode.h"
#include "tree/outputnode.h"
#include "tree/returnnode.h"
#include "tree/functioncallnode.h"
#include "tree/ifnode.h"
#include "tree/whilenode.h"
#include "tree/blocknode.h"
#include "tree/expression/expressionnode.h"
#include "tree/expression/identifiernode.h"
#include "tree/expression/literalnode.h"
#include "tree/expression/operationnode.h"

int yylex();
void yyerror(const char *message);

typedef std::vector<Node*> ParameterList;
typedef std::vector<Node*> VariableList;
typedef std::vector<Node*> ExpressionList;
typedef std::vector<Node*> CommandList;
typedef std::vector<int> DimensionList;

%}

%code requires {
class FunctionDefinitionNode;
}

%union {
  Node* node;
  FunctionDefinitionNode* funcNode;
  std::vector<Node*>* nodes;
  Common::DataType dataType;
  Symbol* symbol;
  int integer;
  std::vector<int>* integers;
}

/* Declaracion de token de gramática de K Language*/
/* Palabras Reservadas (PR) */
%token TK_PR_ENTERO
%token TK_PR_FLOTANTE
%token TK_PR_BOOLEANO
%token TK_PR_CARACTER
%token TK_PR_CADENA
%token TK_PR_SE
%token TK_PR_ENTONCES
%token TK_PR_SENAO
%token TK_PR_ENQUANTO
%token TK_PR_REALIZA
%token TK_PR_ENTRADA
%token TK_PR_SALIDA
%token TK_PR_RETORNA

/* Operadores compuestos (OC) */
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR

/* literales (LIT) */
%token <symbol> TK_LIT_ENTERO
%token <symbol> TK_LIT_FLOTANTE
%token <symbol> TK_LIT_FALSO
%token <symbol> TK_LIT_VERDADERO
%token <symbol> TK_LIT_CARACTER
%token <symbol> TK_LIT_CADENA

/* Identificador */
%token <symbol> TK_IDENTIFICADOR

/* Erro */
%token TOKEN_ERROR

%left TK_OC_OR TK_OC_AND
%left '<' '>' TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE
%left '+' '-'
%left '*' '/'

%type <node> s
%type <node> programa
%type <node> decl_global
%type <nodes> decl_local
%type <node> decl_var
%type <node> decl_vector
%type <integers> decl_vector_dimension
%type <integer> decl_vector_dimension_tamanio
%type <dataType> tipo_var
%type <funcNode> def_funcion
%type <node> llamada_funcion
%type <node> encabezado
%type <nodes> lista_parametros
%type <nodes> lista_parametros_no_vacia
%type <node> parametro
%type <node> comando
%type <node> bloco_comando
%type <nodes> seq_comando
%type <node> asignacion
%type <nodes> vector_dimensiones
%type <node> entrada
%type <node> salida
%type <nodes> lista_expresiones
%type <nodes> lista_expresiones_no_vacia
%type <node> expresion
%type <node> retorna
%type <node> control_flujo

%start s

%%
/* Reglas (y acciones) de la gramática del lenguaje K */

// reglas creadas para poder llamar a la impresion del árbol
s : { $<node>$ = new ProgramNode(); } programa { $$ = $<node>1; /*$$->print(0);*/ $$->generateILOCCode(NULL); $$->printILOC(yyout); /*$$->printSourceCode("");*/ /*$$->printILOC();*/ }
	;

programa: programa decl_global { $<node>0->addChild($2); }
	| programa def_funcion { $<node>0->addChild($2); }
	| decl_global { $<node>0->addChild($1); }
	| def_funcion { $<node>0->addChild($1); }
	;

decl_global: decl_var ';' { $$ = $1; }
	| decl_vector ';' { $$ = $1; }
	;

decl_local: decl_local decl_var ';' { $$->push_back($2); }
	| decl_var ';' { $$ = new VariableList(); $$->push_back($1); }
	;

decl_var: TK_IDENTIFICADOR ':' tipo_var { $$ = new VarDeclarationNode($1->getText(), $3); }
	;

decl_vector: TK_IDENTIFICADOR ':' tipo_var decl_vector_dimension { $$ = new VectorDeclarationNode($1->getText(), $3, $4); }
	;

decl_vector_dimension: decl_vector_dimension '[' decl_vector_dimension_tamanio ']' { $$->push_back($3); }
	| '[' decl_vector_dimension_tamanio ']' { $$ = new DimensionList(); $$->push_back($2); }
	;

decl_vector_dimension_tamanio: TK_LIT_ENTERO { $$ = atoi($1->getText().c_str()); }
	;

tipo_var: TK_PR_ENTERO { $$ = Common::INT; }
	| TK_PR_FLOTANTE { $$ = Common::FLOAT; }
	| TK_PR_BOOLEANO { $$ = Common::BOOL; }
	| TK_PR_CARACTER { $$ = Common::CHAR; }
	| TK_PR_CADENA { $$ = Common::STRING; }
	;

def_funcion: encabezado decl_local '{' seq_comando '}' { $$ = new FunctionDefinitionNode(); $$->setHeader($1); $$->setLocals($2); Node* b = new BlockNode(false); b->addChildren($4); $$->setBlock(b); b->generateILOCCode(NULL); $$->generateILOCCode(NULL); delete $2; }
        | encabezado '{' seq_comando '}' { $$ = new FunctionDefinitionNode(); $$->setHeader($1); Node* b = new BlockNode(false); b->addChildren($3); $$->setBlock(b); b->generateILOCCode(NULL); $$->generateILOCCode(NULL); }
	;

llamada_funcion: TK_IDENTIFICADOR '(' lista_expresiones ')' { $$ = new FunctionCallNode($1, $3); }
	;

/* Function header - begin */
encabezado: TK_IDENTIFICADOR ':' tipo_var '(' { $<node>$ = new HeaderNode($1->getText(), $3); } lista_parametros ')' { $$ = $<node>5; $$->addChildren($6); Scope::setParams($1->getText(), $6) }
	;

lista_parametros: lista_parametros_no_vacia { $$ = $1; }
	| { $$ = new ParameterList(); }
	;

lista_parametros_no_vacia: lista_parametros_no_vacia ',' parametro { $1->push_back($3); }
	| parametro { $$ = new ParameterList(); $$->push_back($1); }
	;

parametro: TK_IDENTIFICADOR ':' tipo_var { $$ = new VarDeclarationNode($1->getText(), $3); }
	;
/* Function header - end */


/* Function body - begin */

comando: bloco_comando { $$ = $1; }
	| control_flujo { $$ = $1; }
	| asignacion { $$ = $1; }
	| entrada { $$ = $1; }
	| salida { $$ = $1; }
	| retorna { $$ = $1; }
	| decl_var ';' { $$ = $1; }
	| llamada_funcion ';' { $$ = $1; }
	;

bloco_comando: '{' { $<node>$ = new BlockNode(); } seq_comando '}' { $<node>$ = $<node>2;  $<node>$->addChildren($3); $$->generateILOCCode(NULL); Scope::popScope(); }
	;

seq_comando: seq_comando comando { $1->push_back($2); }
	| seq_comando comando ';' { $1->push_back($2); }
	| { $$ = new CommandList(); }
	;

asignacion: TK_IDENTIFICADOR '=' expresion ';' { $$ = new AssignmentNode($1->getText(), $3); }
        | TK_IDENTIFICADOR vector_dimensiones '=' expresion ';' { $$ = new AssignmentNode($1->getText(), $2, $4); }
	;

vector_dimensiones: vector_dimensiones '[' expresion ']' { $1->push_back($3); }
        | '[' expresion ']' { $$ = new ExpressionList(); $$->push_back($2); }
	;

entrada: TK_PR_ENTRADA TK_IDENTIFICADOR ';' { $$ = new InputNode($2->getText()); }
	;

salida: TK_PR_SALIDA lista_expresiones_no_vacia ';' { $$ = new OutputNode($2); }
	;

retorna: TK_PR_RETORNA expresion ';' { $$ = new ReturnNode($2); }
	;

lista_expresiones: lista_expresiones_no_vacia { $$ = $1; }
	| { $$ = new ExpressionList(); }
	;

lista_expresiones_no_vacia: lista_expresiones_no_vacia ',' expresion { $1->push_back($3); }
	| expresion { $$ = new ExpressionList(); $$->push_back($1); }
	;

control_flujo: TK_PR_SE '(' expresion ')' TK_PR_ENTONCES comando { $$ = new IfNode($3, $6); }
        | TK_PR_SE '(' expresion ')' TK_PR_ENTONCES comando TK_PR_SENAO comando { $$ = new IfNode($3, $6, $8); }
	| TK_PR_ENQUANTO '(' expresion ')' comando { $$ = new WhileNode($3, $5); }
	;

expresion: TK_IDENTIFICADOR { $$ = new IdentifierNode($1); }
        | TK_IDENTIFICADOR vector_dimensiones { $$ = new IdentifierNode($1, $2); }
	| TK_LIT_ENTERO { $$ = new LiteralNode($1->getText(), Common::INT); }
	| TK_LIT_FLOTANTE { $$ = new LiteralNode($1->getText(), Common::FLOAT); }
	| TK_LIT_FALSO { $$ = new LiteralNode($1->getText(), Common::BOOL); }
	| TK_LIT_VERDADERO { $$ = new LiteralNode($1->getText(), Common::BOOL); }
	| TK_LIT_CARACTER { $$ = new LiteralNode($1->getText(), Common::CHAR); }
	| TK_LIT_CADENA { $$ = new LiteralNode($1->getText(), Common::STRING); }
	| expresion '+' expresion { $$ = new OperationNode(Common::OP_SUM, $1, $3); }
	| expresion '-' expresion { $$ = new OperationNode(Common::OP_SUB, $1, $3); }
	| expresion '*' expresion { $$ = new OperationNode(Common::OP_MULT, $1, $3); }
	| expresion '/' expresion { $$ = new OperationNode(Common::OP_DIV, $1, $3); }
	| expresion '<' expresion { $$ = new OperationNode(Common::OP_LESS, $1, $3); }
	| expresion '>' expresion { $$ = new OperationNode(Common::OP_GREATER, $1, $3); }
	| '+' expresion { $$ = $2; }
	| '-' expresion { $$ = new OperationNode(Common::OP_SUB, $2, NULL); }
	| '(' expresion ')' { $$ = new OperationNode(Common::OP_PAREN, $2, NULL); }
	| expresion TK_OC_LE expresion { $$ = new OperationNode(Common::OP_LE, $1, $3); }
	| expresion TK_OC_GE expresion { $$ = new OperationNode(Common::OP_GE, $1, $3); }
	| expresion TK_OC_EQ expresion { $$ = new OperationNode(Common::OP_EQUAL, $1, $3); }
	| expresion TK_OC_NE expresion { $$ = new OperationNode(Common::OP_NEQUAL, $1, $3); }
	| expresion TK_OC_AND expresion { $$ = new OperationNode(Common::OP_AND, $1, $3); }
	| expresion TK_OC_OR expresion { $$ = new OperationNode(Common::OP_OR, $1, $3); }
	| llamada_funcion { $$ = $1; }
	;

/* Function body - end */

%%
