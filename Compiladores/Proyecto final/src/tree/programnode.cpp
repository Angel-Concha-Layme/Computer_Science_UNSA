#include "programnode.h"
#include <stdio.h>
#include <sstream>
#include "optimizer/optimizer.h"

ProgramNode::ProgramNode(): Node("Programa", Common::NT_PROGRAM) {
	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
	this->baseAddr = Scope::scopeCount() * Common::scopeSize;
	this->currentOffset = 0;
	Scope::pushScope(this);
}

void ProgramNode::printSourceCode(const std::string& end) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode(";\n");
}

void ProgramNode::generateILOCCode(Node* context) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		std::vector<ILOC*> instr = (*it)->getInstructions();
		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );
	}
	this->execSupportCode();
	Optimizer::setInstructions(this->instructions);
}

void ProgramNode::execSupportCode() {
	std::stringstream codeSegSize;
	std::vector<ILOC*> execILOCList;

	codeSegSize << (this->instructions.size()+1) * DataSize::INSTR;
	execILOCList.push_back(new ILOC(Common::ILOC_LOADI, codeSegSize.str(), "", "rBSS", ""));
	this->instructions.insert(this->instructions.begin(), execILOCList.begin(), execILOCList.end());
}
