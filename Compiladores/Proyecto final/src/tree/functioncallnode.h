#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include <string>
#include <vector>
#include "node.h"
#include "expression/expressionnode.h"

class FunctionCallNode : public ExpressionNode {

public:
	FunctionCallNode(Symbol* functionSym, std::vector<Node*>* children);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);
	bool hasDeclaration(Symbol* sym);

private:
	Symbol* symbol;
};

#endif // FUNCTIONCALLNODE_H
