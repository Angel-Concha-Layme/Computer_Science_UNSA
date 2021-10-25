#ifndef HEADERNODE_H
#define HEADERNODE_H

#include <string>
#include <vector>
#include "node.h"
#include "scope.h"
#include "common.h"

class HeaderNode : public Node {
public:
	HeaderNode(const std::string& functionName, Common::DataType dataType);
	std::string getFunctionName() const;
	void setFunctionName(const std::string& value);
	Common::DataType getDataType() const;
	void setDataType(const Common::DataType& value);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:
	std::string functionName;
	Common::DataType dataType;
};

#endif // HEADERNODE_H
