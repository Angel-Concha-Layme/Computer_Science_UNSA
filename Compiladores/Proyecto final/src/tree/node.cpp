#include "node.h"
#include <iostream>
#include <stdio.h>

Node::Node(const std::string& name, const Common::NodeType& nodeType):
	name(name), nodeType(nodeType), parent(NULL), flexOut(yyout), isNewScope(false), hashTable(NULL) {
	this->children = new std::vector<Node*>();
}

Node::Node(const std::string& name, const Common::NodeType& nodeType, std::vector<Node*>* children):
	name(name), nodeType(nodeType), children(children), parent(NULL), flexOut(yyout), isNewScope(false), hashTable(NULL) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->setParent(this);
}

void Node::addChild(Node* child) {
	this->children->push_back(child);
	child->setParent(this);
}

void Node::addChildren(std::vector<Node*>* children) {
	for (std::vector<Node*>::iterator it = children->begin(); it != children->end(); it++) {
		this->children->push_back((*it));
		(*it)->setParent(this);
	}
}

Node* Node::getParent() const {
	return this->parent;
}

void Node::setParent(Node* parent) {
	this->parent = parent;
}

bool Node::getIsNewScope() const {
	return isNewScope;
}

void Node::setIsNewScope(bool value) {
	isNewScope = value;
}

Common::NodeType Node::getNodeType() const {
	return nodeType;
}

void Node::setNodeType(const Common::NodeType& value) {
	nodeType = value;
}

Node* Node::getParentWithScope() const {
	if (parent->getIsNewScope())
		return parent;
	else
		return parent->getParentWithScope();
}

void Node::print(int level) {
	this->printSpaces(level);
	std::cout << this->name << " " << this->currentOffset << "\n";
	for (std::vector<Node*>::iterator it = children->begin(); it != children->end(); it++)
		(*it)->print(level+1);
}

std::string Node::dataTypeToString(const Common::DataType& dataType) {
	switch (dataType) {
	case Common::BOOL:
		return "booleano";
	case Common::INT:
		return "entero";
	case Common::FLOAT:
		return "flotante";
	case Common::CHAR:
		return "caracter";
	case Common::STRING:
		return "cadena";
	default:
		break;
	}

	return "ERRORR!";
}

std::string Node::operationTypeToString(const Common::OperationType& operationType) {
	switch (operationType) {
	case Common::OP_SUM:
		return "+";
	case Common::OP_SUB:
		return "-";
	case Common::OP_MULT:
		return "*";
	case Common::OP_DIV:
		return "/";
	case Common::OP_AND:
		return "&&";
	case Common::OP_OR:
		return "||";
	case Common::OP_LESS:
		return "<";
	case Common::OP_GREATER:
		return ">";
	case Common::OP_LE:
		return "<=";
	case Common::OP_GE:
		return ">=";
	case Common::OP_EQUAL:
		return "==";
	case Common::OP_NEQUAL:
		return "!=";
	default:
		break;
	}

	return "ERRORR!";
}

void Node::printSpaces(int level) {
	for (int i = 0; i < level; i++)
		std::cout << "  ";
}

std::string Node::getName() {
	return this->name;
}

Common::HashTable* Node::getHashTable() {
	return this->hashTable;
}

int Node::getBaseAddr() {
	return this->baseAddr;
}

int Node::getCurrentOffset() {
	return this->currentOffset;
}

void Node::setCurrentOffset(int co) {
	this->currentOffset = co;
}

void Node::printHashTable() {
	std::cout << "==============================\n";
	for (std::tr1::unordered_map<std::string, Symbol*>::iterator it = hashTable->begin(); it != hashTable->end(); it++) {
		Symbol * s = (Symbol*)(*it).second;
		std::cout << s->getText() << " " << s->getDataType() << " " << this->baseAddr + s->getOffset() << "\n";
	}

}

std::string Node::getLastRegister() const {
	return lastRegister;
}

void Node::setLastRegister(const std::string& value) {
	lastRegister = value;
}

std::string Node::getFalseLabel() const {
	return falseLabel;
}

void Node::setFalseLabel(const std::string &value) {
	falseLabel = value;
}

std::string Node::getTrueLabel() const {
	return trueLabel;
}

void Node::setTrueLabel(const std::string &value) {
	trueLabel = value;
}

std::string Node::getNextLabel() const {
    return nextLabel;
}

void Node::setNextLabel(const std::string &value) {
    nextLabel = value;
}

void Node::addInstruction(ILOC* instruction) {
	this->instructions.push_back(instruction);
}

std::vector<ILOC *> Node::getInstructions() {
	return instructions;
}

void Node::setInstructions(const std::vector<ILOC *> &value) {
	instructions = value;
}

void Node::printILOC(FILE * f) {
	for (unsigned int i = 0; i < this->instructions.size(); i++) {
		fprintf(f, "%s\n", this->instructions.at(i)->codeline().c_str());
	}
}


