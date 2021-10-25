#ifndef OPERATIONNODE_H
#define OPERATIONNODE_H

#include "expressionnode.h"
#include "common.h"

class OperationNode : public ExpressionNode {

public:
	OperationNode(const Common::OperationType& operationType, Node* leftSide, Node* rightSide);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:
	Common::OperationType operationType;
};

#endif // OPERATIONNODE_H
