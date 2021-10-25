#include "returnnode.h"
#include <stdio.h>

ReturnNode::ReturnNode(Node* expression): Node("Retorna", Common::NT_RETURN) {
	this->addChild(expression);
}

void ReturnNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "retorna ");
	this->children->at(0)->printSourceCode("");
	fprintf(this->flexOut, "%s", ";\n");
}

void ReturnNode::generateILOCCode(Node* context) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		std::vector<ILOC*> instr = (*it)->getInstructions();

		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );
	}
}
