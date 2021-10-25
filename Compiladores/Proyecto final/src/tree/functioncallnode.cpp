#include "functioncallnode.h"
#include "scope.h"
#include <iostream>
#include <stdio.h>

FunctionCallNode::FunctionCallNode(Symbol* functionSym, std::vector<Node*>* children):
	ExpressionNode("Llamada de funcion", Common::EX_IDENTIFIER), symbol(functionSym) {

	this->addChildren(children);

	if(!this->hasDeclaration(functionSym)) {
		yyerror("function not declared");
	} else {
		Symbol * funDeclSym = Scope::getSymbol(functionSym->getText());
		std::vector<Common::DataType> * params = funDeclSym->getParams();

		if (params->size() != children->size()) {
			yyerror("number of parameters doesn't match");
		} else {

			for (int i = 0; i < params->size(); i++) {
				ExpressionNode* call = dynamic_cast<ExpressionNode*>(children->at(i));

				if (params->at(i) != call->getDataType()) {
					yyerror("parameters type doesn't match");
				}
			}
		}
	}
}

bool FunctionCallNode::hasDeclaration(Symbol* sym) {
	bool found = true;
	if (!Scope::isTokenInScopes(sym->getText())) {
		yyerror("function not declared");
		found = false;
	}
	return found;
}

void FunctionCallNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->symbol->getText().c_str());
	fprintf(this->flexOut, "%s", "(");
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode("");
	fprintf(this->flexOut, "%s", ")");
	fprintf(this->flexOut, "%s", end.c_str());
}

void FunctionCallNode::generateILOCCode(Node* context) {}
