#include "optimizer.h"

FILE* Optimizer::optIn;
FILE* Optimizer::optOut;
std::vector<ILOC*> Optimizer::instructions;

Optimizer::Optimizer() {}

void Optimizer::optimize() {
	if (instructions.size() == 0)
		loadFileToInstructions();
}

//=============================================
// Static methods
//=============================================

FILE* Optimizer::getOptIn() {
	return optIn;
}

void Optimizer::setOptIn(FILE* value) {
	optIn = value;
}

FILE* Optimizer::getOptOut() {
	return optOut;
}

void Optimizer::setOptOut(FILE* value) {
	optOut = value;
}

std::vector<ILOC*> Optimizer::getInstructions() {
	return instructions;
}

void Optimizer::setInstructions(const std::vector<ILOC*>& value) {
	instructions = value;
}

void Optimizer::loadFileToInstructions() {
	char* line;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, optIn)) != -1) {
		std::string lineStr(line);
		Optimizer::instructions.push_back(new ILOC(lineStr));
	}
}
