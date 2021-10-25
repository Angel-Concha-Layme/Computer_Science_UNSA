#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include <string>
#include <vector>
#include "node.h"
#include "scope.h"

class AssignmentNode : public Node {

public:
	AssignmentNode(const std::string& varAssigned, Node* expressionAssigned);
	AssignmentNode(const std::string& varAssigned, std::vector<Node*>* expressionIndexList, Node* expressionAssigned);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);
	bool hasDeclaration(Symbol* sym);


private:
	std::string varName;
};

#endif // ASSIGNMENTNODE_H
