#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAYOR '>'
#define PUNTOYCOMA ';'
#define MENOR '<'
#define COMA ','
#define IGUAL '='
#define SUMA '+'
#define RESTA '-'
#define MULTIPLICACION '*'
#define DIVISION '/'

#define PARI '('
#define PARF ')'
#define CORI '['
#define CORF ']'
#define LLAVI '{'
#define LLAVF '}'

#define ID 256
#define NUM 257
#define MAYORIGUAL 258
#define MENORIGUAL 259
#define ASIGNACION 260
#define DIFERENTEDE 261
#define WHILE 262
#define IF 263
#define FOR 264

int scaner();
void mostrar(int);
int espalres();
char lexema[80];
FILE *f;


int main(int n, char *pal[]){
    int token;
    f=stdin; //entrada estandar del teclado
    if(n==2) //si se especifico un archivo de lectura
    {
        f=fopen(pal[1],"rt"); //lectura modo texto
        if(f==NULL)
            f=stdin;
    }
    if(f==stdin) //la lectura sera desde la entrada estandar
        printf("Ingrese texto ........ termine con Ctrl z \n");
    while(1)
    {
        token=scaner();
        if(token==EOF) break;
            mostrar(token);
    }
    if(f !=stdin) // si la entrada fue de un archivo
        fclose(f); // entonces cerrar el archivo.
}//fin del main


int scaner()
{
    int c,i;
    do c=fgetc(f); while(isspace(c)); //ignora blancos
    if(c==EOF) 
        return EOF;
    if(isalpha(c)) //regla del ID
    {
        i=0;
    do{
        lexema[i++]=c;
        c=fgetc(f);
    }while(isalnum(c)||c=='_');
    
    lexema[i]=0;
    ungetc(c,f); //se devuelve c al flujo de entrada
    i=espalres(); // verifica si es palabra reservada
    if(i>=0)
        return i;
    return ID; // se trata de un ID
    }

    if(isdigit(c)) //regla del NUM
    {
        i=0;
        do{
            lexema[i++]=c;
            c=fgetc(f);
        }while(isdigit(c));
        lexema[i]=0;
        ungetc(c,f);
        return NUM;
    }

    if((c==';')||(c=='(')||(c==')')||(c==',')||(c=='[')||(c==']')||(c=='{')||(c=='}')||(c=='+')||(c=='-')||(c=='*')||(c=='/')){
        return c;
    }

    if(c=='>') //regla de ">" o ">="
    {
        c=fgetc(f);
        if(c=='=') //return MAYORIGUAL
        {
            lexema[0]='>'; lexema[1]='='; lexema[2]=0;
            return MAYORIGUAL;
        }
    ungetc(c,f);
    return MAYOR; //return MAYOR
    }

    if(c=='<') //regla de "<" o "<="
    {
        c=fgetc(f);
        if(c=='=') //return MENORIGUAL
        {
            lexema[0]='<'; lexema[1]='='; lexema[2]=0;
            return MENORIGUAL;
        }
    ungetc(c,f);
    return MENOR; //return MENOR
    }

    if(c=='=') //regla de "=" o "=="
    {
        c=fgetc(f);
        if(c=='=') //return ASIGNACION
        {
            lexema[0]='='; lexema[1]='='; lexema[2]=0;
            return ASIGNACION;
        }
    ungetc(c,f);
    return IGUAL; //return MAYOR
    }

    if(c=='!') //regla de "!=" 
    {
        c=fgetc(f);
        if(c=='=') //return ASIGNACION
        {
            lexema[0]='!'; lexema[1]='='; lexema[2]=0;
            return DIFERENTEDE;
        }
    ungetc(c,f);
    }

}//fin de scaner

int espalres()
{
    if(strcmp(lexema,"while")==0) return WHILE;
    if(strcmp(lexema,"if")==0) return IF;
    if(strcmp(lexema,"for")==0) return FOR;
    return -1;
}

void mostrar(int token)
{
    switch(token)
    {
        case ID: printf("token = ID [%s] \n",lexema); break;
        case NUM: printf("token = NUM [%s] \n",lexema); break;
        case MAYOR: printf("token = MAYOR [%c] \n",token); break;
        case MAYORIGUAL: printf("token = MAYORIGUAL [%s]\n",lexema); break;
        case MENOR: printf("token = MENOR [%c] \n",token); break;
        case MENORIGUAL: printf("token = MENORIGUAL [%s] \n",lexema); break;
        case IGUAL: printf("token = IGUAL [%c] \n",token); break;
        case DIFERENTEDE: printf("token = DIFERENTEDE [%s] \n",lexema); break;
        case ASIGNACION: printf("token = ASIGNACION [%s] \n",lexema); break;
        case PUNTOYCOMA: printf("token = PUNTOYCOMA [%c]\n",token); break;
        case COMA: printf("token = COMA [%c]\n",token); break;
        case LLAVI: printf("token = LLAVI [%c]\n",token); break;
        case LLAVF: printf("token = LLAVF [%c]\n",token); break;
        case CORI: printf("token = CORI [%c] \n",token); break;
        case CORF: printf("token = CORF [%c] \n",token); break;
        case PARI: printf("token = PARI [%c] \n",token); break;  
        case PARF: printf("token = PARF [%c] \n",token); break;
        case SUMA:printf("token = SUMA [%c] \n",token); break;
        case RESTA:printf("token = RESTA [%c] \n",token); break;
        case MULTIPLICACION:printf("token = MULTIPLICACION [%c] \n",token); break;
        case DIVISION:printf("token = DIVISION [%c] \n",token); break;
        case WHILE: printf("token = WHILE [%s] \n",lexema); break;
        case IF: printf("token = IF [%s] \n",lexema); break;
        case FOR: printf("token = FOR [%s] \n ",lexema); break;
    }
}