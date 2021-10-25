#ifndef LITERALNODE_H
#define LITERALNODE_H

#include <string>
#include "expressionnode.h"
#include "common.h"

class LiteralNode : public ExpressionNode {

public:
	LiteralNode(const std::string& literal, const Common::DataType& dataType);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:
	std::string literal;
};

#endif // LITERALNODE_H
