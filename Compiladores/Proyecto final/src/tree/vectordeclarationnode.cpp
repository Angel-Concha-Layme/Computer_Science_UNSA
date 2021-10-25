#include "vectordeclarationnode.h"
#include <stdio.h>
#include <sstream>

VectorDeclarationNode::VectorDeclarationNode(const std::string& vectorName, Common::DataType& dataType, std::vector<int>* dimensions):
	Node("Declaracion de vector", Common::NT_VECTOR_DECLARATION), vectorName(vectorName), dataType(dataType), dimensions(dimensions) {

	if (Scope::isTokenInClosestScope(vectorName)) {
		yyerror("Vector ya declarado en este ámbito.");
	} else {

		Symbol* sym = new Symbol(vectorName, Common::VECTOR_VAR, dataType);

		Node* scope = Scope::getScope();
		// busca el desplazamiento del alcance actual, este será el desplazamiento de la nueva variable en el alcance
		int coffset = scope->getCurrentOffset();
		sym->setOffset(coffset);
		// calcula el desplazamiento del vector escaneando la lista de dimensiones
		int size = 0;
		int dtSize = Symbol::getDataTypeSize(dataType);
		for (unsigned int i = 0; i < dimensions->size(); i++) {
			size += dimensions->at(i) * dtSize;
		}

		// actualiza el desplazamiento de alcance actual
		this->setCurrentOffset(coffset);
		scope->setCurrentOffset(coffset + size);

		Scope::addSymbol(sym);
	}
}

void VectorDeclarationNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->vectorName.c_str());
	fprintf(this->flexOut, "%s", ": ");
	fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
	for (unsigned int i = 0; i < this->dimensions->size(); i++) {
		std::stringstream sizeStr;
		sizeStr << this->dimensions->at(i);
		fprintf(this->flexOut, "%s", "[");
		fprintf(this->flexOut, "%s", sizeStr.str().c_str());
		fprintf(this->flexOut, "%s", "]");
	}
	fprintf(this->flexOut, "%s", end.c_str());
}

void VectorDeclarationNode::generateILOCCode(Node* context) {}
