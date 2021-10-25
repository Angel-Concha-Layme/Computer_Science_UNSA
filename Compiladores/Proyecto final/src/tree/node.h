#ifndef NODE_H
#define NODE_H

#include <vector>
#include <tr1/unordered_map>
#include <string>
#include "common.h"
#include "symbol.h"
#include "iloc.h"

extern FILE* yyout;
void yyerror(const char *message);

class Node {

public:
	Node(const std::string& name, const Common::NodeType& nodeType);
	Node(const std::string& name, const Common::NodeType& nodeType, std::vector<Node*>* children);
	void addChild(Node* child);
	void addChildren(std::vector<Node*>* children);
	Node* getParent() const;
	void setParent(Node* parent);
	bool getIsNewScope() const;
	void setIsNewScope(bool value);
	Common::NodeType getNodeType() const;
	void setNodeType(const Common::NodeType& value);
	Node* getParentWithScope() const;
	void print(int level);
	virtual void printSourceCode(const std::string& end) = 0;
	virtual void generateILOCCode(Node* context) = 0;
	std::string getName();
	Common::HashTable* getHashTable();
	int getBaseAddr();
	int getCurrentOffset();
	void setCurrentOffset(int co);
	void printHashTable();
	std::string getLastRegister() const;
	void setLastRegister(const std::string& value);

	std::string getTrueLabel() const;
	void setTrueLabel(const std::string &value);

	std::string getFalseLabel() const;
	void setFalseLabel(const std::string &value);

	std::string getNextLabel() const;
	void setNextLabel(const std::string &value);

	std::vector<ILOC *> getInstructions();
	void setInstructions(const std::vector<ILOC *> &value);

	void printILOC(FILE * f);

	void addInstruction(ILOC* instruction);

	std::vector<ILOC*> instructions;

protected:
	std::string dataTypeToString(const Common::DataType& dataType);
	std::string operationTypeToString(const Common::OperationType& operationType);
	std::string name;
	Common::NodeType nodeType;
	std::vector<Node*>* children;
	Node* parent;
	FILE* flexOut;
	bool isNewScope;
	Common::HashTable* hashTable;
	int baseAddr;
	int currentOffset;
	std::string lastRegister;

private:
	void printSpaces(int level);

	std::string trueLabel;
	std::string falseLabel;
	std::string nextLabel;


};

#endif // NODE_H
