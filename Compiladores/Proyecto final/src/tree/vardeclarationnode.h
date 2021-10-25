#ifndef VARDECLARATIONNODE_H
#define VARDECLARATIONNODE_H

#include <string>
#include "node.h"
#include "scope.h"
#include "common.h"

class VarDeclarationNode : public Node {

public:
	VarDeclarationNode(const std::string& varName, Common::DataType dataType);
	std::string getVarName() const;
	void setVarName(const std::string& value);
	Common::DataType getDataType() const;
	void setDataType(const Common::DataType& value);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:
	std::string varName;
	Common::DataType dataType;
};

#endif // VARDECLARATIONNODE_H
