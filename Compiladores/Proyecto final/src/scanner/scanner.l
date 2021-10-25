%{
#include "tree/common.h"
#include "symbol.h"
#include "tree/node.h"
#include "parser/parser.hpp"

int numeroLinea = 1;
%}

%x COMM

letra [A-Za-z_]
digito [0-9]

%%
entero { return TK_PR_ENTERO; }
flotante { return TK_PR_FLOTANTE; }
booleano { return TK_PR_BOOLEANO; }
caracter { return TK_PR_CARACTER; }
cadena { return TK_PR_CADENA;	}
se { return TK_PR_SE; }
entonces { return TK_PR_ENTONCES;	}
seno { return TK_PR_SENAO;	}
mientras { return TK_PR_ENQUANTO;	}
realiza { return TK_PR_REALIZA;	}
entrada { return TK_PR_ENTRADA;	}
salida { return TK_PR_SALIDA;	}
retorna { return TK_PR_RETORNA;	}

"verdadero" { yylval.symbol = new Symbol(yytext, Common::LIT_BOOL); return TK_LIT_VERDADERO; }
"falso" { yylval.symbol = new Symbol(yytext, Common::LIT_BOOL); return TK_LIT_FALSO; }

"<=" { return TK_OC_LE; }
">=" { return TK_OC_GE; }
"==" { return TK_OC_EQ; }
"!=" { return TK_OC_NE; }
"&&" { return TK_OC_AND; }
"||" { return TK_OC_OR; }

","|";"|":"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"*"|"/"|"<"|">"|"="|"!"|"&"|"$" { return yytext[0];	}

{letra}({letra}|{digito})* { yylval.symbol = new Symbol(yytext, Common::IDENTIFIER); return TK_IDENTIFICADOR; }
{digito}+ { yylval.symbol = new Symbol(yytext, Common::LIT_INT); return TK_LIT_ENTERO; }
{digito}+"."{digito}+ { yylval.symbol = new Symbol(yytext, Common::LIT_FLOAT); return TK_LIT_FLOTANTE; }
\'.\' { yylval.symbol = new Symbol(yytext, Common::LIT_CHAR); return TK_LIT_CARACTER; }
\"[^"]*\" { yylval.symbol = new Symbol(yytext, Common::LIT_STRING); return TK_LIT_CADENA; }

"//".* {}

"/*" { BEGIN(COMM); }
<COMM>"*/" { BEGIN(INITIAL); }
<COMM>"\n" { numeroLinea++; }
<COMM>.

\n { numeroLinea++; }
[ \t] { }
. { return TOKEN_ERROR; }

%%