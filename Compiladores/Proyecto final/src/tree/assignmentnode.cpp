#include "assignmentnode.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "expression/expressionnode.h"
#include "expression/identifiernode.h"

AssignmentNode::AssignmentNode(const std::string &varAssigned, Node* expressionAssigned):
	Node("Asignacion", Common::NT_ASSIGNMENT), varName(varAssigned) {

	this->addChild(expressionAssigned);


	Symbol* symbol = Scope::getSymbol(this->varName);
	ExpressionNode* expr = dynamic_cast<ExpressionNode*>(expressionAssigned);

	if (symbol != NULL && this->hasDeclaration(symbol)) {
		if (symbol->getTokenType() != Common::VARIABLE && symbol->getTokenType() != Common::VECTOR_VAR) {
			yyerror("invalid operation.");
		}	else if (symbol->getDataType() != expr->getDataType()) {
			yyerror("variable assignment must be of equivalent data types");
		} else {
			this->generateILOCCode(NULL);
		}
	} else {
		yyerror("identifier not declared");
	}

}

AssignmentNode::AssignmentNode(const std::string &varAssigned, std::vector<Node*>* expressionIndexList, Node* expressionAssigned):
	Node("Asignacion", Common::NT_ASSIGNMENT), varName(varAssigned) {

	this->addChildren(expressionIndexList);
	this->addChild(expressionAssigned);

	Symbol* symbol = Scope::getSymbol(this->varName);
	ExpressionNode* expr = dynamic_cast<ExpressionNode*>(expressionAssigned);

	if (symbol != NULL && this->hasDeclaration(symbol)) {
		if (symbol->getTokenType() != Common::VARIABLE && symbol->getTokenType() != Common::VECTOR_VAR) {
			yyerror("invalid operation.");
		}	else if (symbol->getDataType() != expr->getDataType()) {
			yyerror("variable assignment must be of equivalent data types");
		} else {

			for (int i = 0; i < expressionIndexList->size(); i++) {
				ExpressionNode* expr = dynamic_cast<ExpressionNode*>(expressionIndexList->at(i));

				if (expr->getDataType() != Common::INT) {
					yyerror("vector index must be of type 'entero'");
				}
			}

			this->generateILOCCode(NULL);
		}
	} else {
		yyerror("identifier not declared");
	}

	/*
	if (symbol->getDataType() != expr->getDataType()) {
		yyerror("variable assignment must be of equivalent data types");
	} else {
		if (this->hasDeclaration(symbol)) {

			for (int i = 0; i < expressionIndexList->size(); i++) {
				ExpressionNode* expr = dynamic_cast<ExpressionNode*>(expressionIndexList->at(i));

				if (expr->getDataType() != Common::INT) {
					yyerror("vector index must be of type 'entero'");
				}
			}

			this->generateILOCCode(NULL);
		}
	}*/
}

bool AssignmentNode::hasDeclaration(Symbol* sym) {
	bool found = true;
	if (!Scope::isTokenInScopes(sym->getText())) {
		yyerror("variable not declared");
		found = false;
	}
	return found;
}

void AssignmentNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 1) {
		fprintf(this->flexOut, "%s", this->varName.c_str());
		fprintf(this->flexOut, "%s", " = ");
		this->children->at(0)->printSourceCode("");
		fprintf(this->flexOut, "%s", end.c_str());
	} else {
		fprintf(this->flexOut, "%s", this->varName.c_str());
		for (unsigned int i = 0; i < this->children->size() - 1; i++) {
			fprintf(this->flexOut, "%s", "[");
			this->children->at(i)->printSourceCode("");
			fprintf(this->flexOut, "%s", "]");
		}
		fprintf(this->flexOut, "%s", " = ");
		this->children->at(this->children->size()-1)->printSourceCode("");
		fprintf(this->flexOut, "%s", end.c_str());
	}
}

void AssignmentNode::generateILOCCode(Node* context) {
	if (this->children->size() == 1) { // Variable
		Symbol* symbol = Scope::getSymbol(this->varName);
		Node* symbolScope = Scope::getScope(this->varName);
		Node* expressionAssigned = this->children->at(0);
		std::string registerBaseAddress = (symbolScope->getNodeType() == Common::NT_PROGRAM) ? "rBSS" : "rFP";
		std::stringstream symbolOffsetStr;
		symbolOffsetStr << symbol->getOffset();

		std::vector<ILOC*> instr = expressionAssigned->getInstructions();

		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );

		ILOC* instruction = new ILOC(Common::ILOC_STOREAI, expressionAssigned->getLastRegister(), "", registerBaseAddress, symbolOffsetStr.str());
		this->addInstruction(instruction);
	}
}
