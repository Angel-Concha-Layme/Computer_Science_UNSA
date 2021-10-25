#include "literalnode.h"
#include <stdio.h>
#include <sstream>
#include <iostream>


LiteralNode::LiteralNode(const std::string& literal, const Common::DataType& dataType):
	ExpressionNode("Expresion literal", Common::EX_LITERAL, dataType), literal(literal) {

	this->generateILOCCode(NULL);
}

void LiteralNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", literal.c_str());
}

void LiteralNode::generateILOCCode(Node* context) {
	std::string finalValue = (literal.compare("verdadero") == 0) ? "true" : (literal.compare("false") == 0) ? "false": literal;
	std::string* registerName = ILOC::getRegister(finalValue);
	ILOC* instruction = new ILOC(Common::ILOC_LOADI, finalValue, "", *registerName, "");
	this->addInstruction(instruction);
	this->setLastRegister(*registerName);
}
