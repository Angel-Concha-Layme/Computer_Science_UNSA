#include "blocknode.h"
#include <stdio.h>

BlockNode::BlockNode(): Node("Bloquear", Common::NT_BLOCK) {
	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
	this->baseAddr = Scope::scopeCount() * Common::scopeSize;
	this->currentOffset = 0;
	Scope::pushScope(this);
}

BlockNode::BlockNode(bool isNewScope): Node("Bloquear", Common::NT_BLOCK) {
	this->isNewScope = isNewScope;
	if (this->isNewScope) {
		this->hashTable = new Common::HashTable();
		this->baseAddr = Scope::scopeCount() * Common::scopeSize;
		this->currentOffset = 0;
		Scope::pushScope(this);
	}
}

void BlockNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "{\n");
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->printSourceCode(";\n");
	}
	fprintf(this->flexOut, "%s", "}\n");
}

void BlockNode::generateILOCCode(Node* context) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		std::vector<ILOC*> instr = (*it)->getInstructions();

		//this->instructions.reserve( this->instructions.size() + instr.size() ); // preallocate memory
		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );
	}
}
