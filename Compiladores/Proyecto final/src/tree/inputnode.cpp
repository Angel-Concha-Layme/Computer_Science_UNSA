#include "inputnode.h"
#include <stdio.h>

InputNode::InputNode(const std::string& varName): Node("Entrada", Common::NT_INPUT), varName(varName) {}

void InputNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "entrada ");
	fprintf(this->flexOut, "%s", this->varName.c_str());
	fprintf(this->flexOut, "%s", ";\n");
}

void InputNode::generateILOCCode(Node* context) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		std::vector<ILOC*> instr = (*it)->getInstructions();

		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );
	}
}
