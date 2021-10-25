#ifndef WHILENODE_H
#define WHILENODE_H

#include "node.h"

class WhileNode : public Node {

public:
	WhileNode(Node* expression, Node* command);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

	std::string getTrueLabel() const;
	void setTrueLabel(const std::string &value);

	std::string getFalseLabel() const;
	void setFalseLabel(const std::string &value);

private:
	std::string trueLabel;
	std::string falseLabel;


};

#endif // WHILENODE_H
