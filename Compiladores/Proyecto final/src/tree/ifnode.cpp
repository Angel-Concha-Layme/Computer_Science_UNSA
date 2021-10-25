#include "ifnode.h"
#include "expression/expressionnode.h"
#include <stdio.h>

IfNode::IfNode(): Node("Se", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->generateILOCCode(NULL);
}

IfNode::IfNode(Node* expression, Node* commandThen): Node("Se", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->addChild(expression);
	this->addChild(commandThen);
	this->generateILOCCode(NULL);
}

IfNode::IfNode(Node* expression, Node* commandThen, Node* commandElse): Node("Se Seno", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->addChild(expression);
	this->addChild(commandThen);
	this->addChild(commandElse);
	this->generateILOCCode(NULL);
}

void IfNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "se (");
	this->children->at(0)->printSourceCode("");
	fprintf(this->flexOut, "%s", ") entonces\n");
	this->children->at(1)->printSourceCode("");
	if (this->children->size() == 3) {
		fprintf(this->flexOut, "%s", "seno\n");
		this->children->at(2)->printSourceCode("");
	}
}

void IfNode::generateILOCCode(Node* context) {
	ILOC* instruction;

	// condicion para if
	Node* condNode = dynamic_cast<Node*>(this->children->at(0));
	std::vector<ILOC*> condInstr = condNode->getInstructions();

	// instrucciones generadas por el nodo de condicion
	this->instructions.insert(this->instructions.end(), condInstr.begin(), condInstr.end());

	// agrega una instruccion de comparacion de registros, saltando a un label determinada
	instruction = new ILOC(Common::ILOC_CBR, condNode->getLastRegister(), "", this->getTrueLabel(), this->getFalseLabel());
	this->addInstruction(instruction);

	// codigo si es verdadero
	Node* thenNode = dynamic_cast<Node*>(this->children->at(1));
	std::vector<ILOC*> thenInstr = thenNode->getInstructions();

	if (!thenInstr.at(0)->hasLabel()) {
		thenInstr.at(0)->setLabel(this->getTrueLabel());
	} else {
		// agrega un label de condicion falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getTrueLabel(), "", "", "", "");
		this->addInstruction(instruction);
	}

	// INstrucciones generadas por el nodo -> codigo "verdadero"
	this->instructions.insert(this->instructions.end(), thenInstr.begin(), thenInstr.end());

	// si existe otro 
	if (this->children->size() == 3) {
		Node* elseNode = dynamic_cast<Node*>(this->children->at(2));
		std::vector<ILOC*> elseInstr = elseNode->getInstructions();

		// agrega un salto para el proximo comando
		instruction = new ILOC(Common::ILOC_JUMPI, "", "", this->getNextLabel(), "");
		this->addInstruction(instruction);

		if (!elseInstr.at(0)->hasLabel()) {
			elseInstr.at(0)->setLabel(this->getFalseLabel());
		} else {
			// agrega un label de condicion falsa
			instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
			this->addInstruction(instruction);
		}

		// instrucciones generadas por el nodo de codigo "verdadero"
		this->instructions.insert(this->instructions.end(), elseInstr.begin(), elseInstr.end());

		// adiciona o label para o proximo trecho de codigo a ser executado
		instruction = new ILOC(Common::ILOC_NOP, this->getNextLabel(), "", "", "", "");
		this->addInstruction(instruction);
	} else {
		// agrega un label de condicion falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
		this->addInstruction(instruction);
	}
}
