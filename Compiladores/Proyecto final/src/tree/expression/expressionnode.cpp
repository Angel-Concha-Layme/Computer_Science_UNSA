#include "expressionnode.h"

ExpressionNode::ExpressionNode(const std::string& name, const Common::ExpressionType& expressionType):
	Node(name, Common::NT_EXPRESSION), expressionType(expressionType) {}

ExpressionNode::ExpressionNode(const std::string& name, const Common::ExpressionType& expressionType, const Common::DataType& dataType):
	Node(name, Common::NT_EXPRESSION), expressionType(expressionType), dataType(dataType) {}

Common::DataType ExpressionNode::getDataType() const {
	return dataType;
}

void ExpressionNode::setDataType(const Common::DataType &value) {
	dataType = value;
}

Common::ExpressionType ExpressionNode::getExpressionType() const {
	return expressionType;
}

void ExpressionNode::setExpressionType(const Common::ExpressionType& value) {
	expressionType = value;
}
