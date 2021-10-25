#include "headernode.h"
#include <stdio.h>

HeaderNode::HeaderNode(const std::string &functionName, Common::DataType dataType):
	Node("Cabecalho", Common::NT_HEADER), functionName(functionName), dataType(dataType) {

	// Agrega la funcion a la tabla hash antes de crear el nuevo alcance
	Symbol * sym = new Symbol(functionName, Common::FUNCTION, dataType);
	Scope::addSymbol(sym);

	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
	this->baseAddr = Scope::scopeCount() * Common::scopeSize;
	this->currentOffset = 0;
	Scope::pushScope(this);
}

Common::DataType HeaderNode::getDataType() const {
	return dataType;
}

void HeaderNode::setDataType(const Common::DataType& value) {
	dataType = value;
}

std::string HeaderNode::getFunctionName() const {
	return functionName;
}

void HeaderNode::setFunctionName(const std::string& value) {
	functionName = value;
}


void HeaderNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->functionName.c_str());
	fprintf(this->flexOut, "%s", ": ");
	fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
	fprintf(this->flexOut, "%s", " (");
	for (unsigned int i = 0; i < this->children->size(); i++) {
		this->children->at(i)->printSourceCode("");
		if (i != this->children->size()-1)
			fprintf(this->flexOut, "%s", ", ");
	}
	fprintf(this->flexOut, "%s", ")");
}



void HeaderNode::generateILOCCode(Node* context) {}


