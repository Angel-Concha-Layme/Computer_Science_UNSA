#ifndef INPUTNODE_H
#define INPUTNODE_H

#include <string>
#include "node.h"

class InputNode : public Node {

public:
	InputNode(const std::string& varName);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:	
	std::string varName;
};

#endif // INPUTNODE_H
