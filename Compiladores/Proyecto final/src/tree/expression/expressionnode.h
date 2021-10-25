#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <string>
#include "node.h"
#include "common.h"
#include "symbol.h"

class ExpressionNode : public Node {

public:
	ExpressionNode(const std::string& name, const Common::ExpressionType& expressionType);
	ExpressionNode(const std::string& name, const Common::ExpressionType& expressionType, const Common::DataType& dataType);
	Common::DataType getDataType() const;
	void setDataType(const Common::DataType& value);
	Common::ExpressionType getExpressionType() const;
	void setExpressionType(const Common::ExpressionType& value);

protected:
	virtual void printSourceCode(const std::string& end) = 0;
	Common::ExpressionType expressionType;
	Common::DataType dataType;
};

#endif // EXPRESSIONNODE_H
