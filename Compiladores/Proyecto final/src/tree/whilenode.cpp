#include "whilenode.h"
#include <stdio.h>

WhileNode::WhileNode(Node *expression, Node *command): Node("Mientras", Common::NT_WHILE) {
	this->addChild(expression);
	this->addChild(command);
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->generateILOCCode(NULL);
}

void WhileNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "mientras (");
	this->children->at(0)->printSourceCode("");
	fprintf(this->flexOut, "%s", ")\n");
	this->children->at(1)->printSourceCode(";\n");
}

std::string WhileNode::getFalseLabel() const {
	return falseLabel;
}

void WhileNode::setFalseLabel(const std::string &value) {
	falseLabel = value;
}

std::string WhileNode::getTrueLabel() const {
	return trueLabel;
}

void WhileNode::setTrueLabel(const std::string &value) {
	trueLabel = value;
}

void WhileNode::generateILOCCode(Node* context) {
	ILOC* instruction;

	// condicion de while
	Node* condNode = dynamic_cast<Node*>(this->children->at(0));
	std::vector<ILOC*> condInstr = condNode->getInstructions();

	if (!condInstr.at(0)->hasLabel()) {
		condInstr.at(0)->setLabel(this->getFalseLabel());
	} else {
		// agrega un label de condicion falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
		this->addInstruction(instruction);
	}

	this->instructions.insert(this->instructions.end(), condInstr.begin(), condInstr.end());

	// agrega una instruccion de comparacion de registros, saltando a un label determinado
	instruction = new ILOC(Common::ILOC_CBR, condNode->getLastRegister(), "", this->getTrueLabel(), this->getNextLabel());
	this->addInstruction(instruction);

	// codigo si es verdadero
	Node* doNode = dynamic_cast<Node*>(this->children->at(1));
	std::vector<ILOC*> doInstr = doNode->getInstructions();

	// adiciona o label "verdadero" en la siguiente instruccion sintetizada, si la hubiera, agréguela en un NOP
	if (!doInstr.at(0)->hasLabel()) {
		doInstr.at(0)->setLabel(this->getTrueLabel());
	} else {
		// adiciona o label de condicion verdadera
		instruction = new ILOC(Common::ILOC_NOP, this->getTrueLabel(), "", "", "", "");
		this->addInstruction(instruction);
	}

	this->instructions.insert(this->instructions.end(), doInstr.begin(), doInstr.end());

	// adiciona jump incondicional para a condicion do while
	instruction = new ILOC(Common::ILOC_JUMPI, "", "", this->getFalseLabel(), "");
	this->addInstruction(instruction);

	// adiciona o label de condicion verdadera
	instruction = new ILOC(Common::ILOC_NOP, this->getNextLabel(), "", "", "", "");
	this->addInstruction(instruction);
}

