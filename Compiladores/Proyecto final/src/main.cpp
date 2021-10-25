#include <stdio.h>
#include <stdlib.h>
#include "iloc.h"
#include "optimizer/optimizer.h"

extern "C" FILE* yyin;
extern "C" FILE* yyout;
extern "C" int numeroLinea;
int yyparse (void);

int getLineNumber(void) {
	return numeroLinea;
}

void yyerror(char const *mensagem) {
	fprintf(stderr, "Error on line %d, %s\n", getLineNumber(), mensagem);
	exit(1);
}

std::string getExtension(const std::string fileName) {
	return fileName.substr(fileName.find_last_of(".")+1);
}

int main(int argc, char **argv){

	// verifica validez de parametro  entrada
	if(argc < 3) {
		printf("Use main <input_file_name> <output_file_name>\n");
		exit(1);
	}

	std::string inputFileExtension(getExtension(argv[1]));

	if (inputFileExtension.compare("i") != 0) { // If is not only in optimizing mode
		// inicializa arquivos para lectura/escritura
		yyin  = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");

		ILOC::initRegisters();

		// chama o parser...
		yyparse();

		Optimizer::setOptOut(yyout);
		Optimizer::optimize();

		// cierra archivos
		fclose(yyin);
		fclose(yyout);
	} else { // If is in optmizing mode
		FILE* optIn = fopen(argv[1], "r");
		FILE* optOut = fopen(argv[2], "w");
		Optimizer::setOptIn(optIn);
		Optimizer::setOptOut(optOut);
		Optimizer::optimize();
		fclose(optIn);
		fclose(optOut);
	}

	// inicializa archivos para lectura/escritura
	yyin  = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	ILOC::initRegisters();

	// llama aparser...
	yyparse();

	// cierra archivos
	fclose(yyin);
	fclose(yyout);

	exit(0);
}
