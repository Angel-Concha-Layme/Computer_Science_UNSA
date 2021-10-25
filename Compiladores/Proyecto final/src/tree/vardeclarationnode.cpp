#include "vardeclarationnode.h"
#include <stdio.h>

VarDeclarationNode::VarDeclarationNode(const std::string& varName, Common::DataType dataType):
	Node("Declaracion de variable", Common::NT_VAR_DECLARATION), varName(varName), dataType(dataType) {

	if (Scope::isTokenInClosestScope(varName)) {
		yyerror("Variable ya declarada en este ambito.");
	} else {

		Symbol * sym = new Symbol(varName, Common::VARIABLE, dataType);
		Node* scope = Scope::getScope();

		// busca el desplazamiento del alcance actual, este será el desplazamiento de la nueva variable en el alcance
		int coffest = scope->getCurrentOffset();
		sym->setOffset(coffest);
		// actualiza el desplazamiento de alcance actual
		this->setCurrentOffset(coffest);
		scope->setCurrentOffset(coffest + Symbol::getDataTypeSize(dataType));

		Scope::addSymbol(sym);
	}
}

Common::DataType VarDeclarationNode::getDataType() const {
	return dataType;
}

void VarDeclarationNode::setDataType(const Common::DataType& value) {
	dataType = value;
}

std::string VarDeclarationNode::getVarName() const {
	return varName;
}

void VarDeclarationNode::setVarName(const std::string& value) {
	varName = value;
}

void VarDeclarationNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->varName.c_str());
	fprintf(this->flexOut, "%s", ": ");
	fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
	fprintf(this->flexOut, "%s", end.c_str());
}

void VarDeclarationNode::generateILOCCode(Node* context) {}
