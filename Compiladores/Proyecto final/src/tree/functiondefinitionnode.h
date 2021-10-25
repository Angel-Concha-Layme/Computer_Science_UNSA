#ifndef FUNCTIONDEFINITIONNODE_H
#define FUNCTIONDEFINITIONNODE_H

#include <string>
#include <vector>
#include "node.h"

class FunctionDefinitionNode : public Node {

public:
	FunctionDefinitionNode();
	void setHeader(Node* header);
	void setLocals(std::vector<Node*>* locals);
	void setBlock(Node* block);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

};

#endif // FUNCTIONDEFINITIONNODE_H
