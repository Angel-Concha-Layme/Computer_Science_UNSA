#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "iloc.h"

class Optimizer {

public:
	Optimizer();
	static FILE* getOptIn();
	static void setOptIn(FILE* value);
	static FILE* getOptOut();
	static void setOptOut(FILE* value);
	static std::vector<ILOC*> getInstructions();
	static void setInstructions(const std::vector<ILOC*>& value);
	static void optimize();

private:
	static void loadFileToInstructions();
	static FILE* optIn;
	static FILE* optOut;
	static std::vector<ILOC*> instructions;
};

#endif // OPTIMIZER_H
