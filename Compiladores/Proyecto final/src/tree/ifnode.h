#ifndef IFNODE_H
#define IFNODE_H

#include "node.h"

class IfNode : public Node {

public:
	IfNode();
	IfNode(Node* expression, Node* commandThen);
	IfNode(Node* expression, Node* commandThen, Node* commandElse);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);



};

#endif // IFNODE_H
