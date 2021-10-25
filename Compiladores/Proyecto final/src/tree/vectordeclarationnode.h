#ifndef VECTORDECLARATIONNODE_H
#define VECTORDECLARATIONNODE_H

#include <string>
#include "node.h"
#include "scope.h"
#include "common.h"

class VectorDeclarationNode : public Node {

public:
	VectorDeclarationNode(const std::string& vectorName, Common::DataType& dataType, std::vector<int>* dimensions);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:
	std::string vectorName;
	Common::DataType dataType;
	std::vector<int>* dimensions;
};

#endif // VECTORDECLARATIONNODE_H
