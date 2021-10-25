#include "iloc.h"
#include <stdio.h>
#include <sstream>
#include <algorithm>

std::vector<std::string> ILOC::registersBeingUsed (MAX_REGISTERS);
Dictionary ILOC::registersByIdentifier;
int ILOC::labelCount;

ILOC::ILOC(Common::ILOC_OperationType type, const std::string& src1, const std::string& src2, const std::string& dst1, const std::string& dst2):
	type(type), src1(src1), src2(src2), dst1(dst1), dst2(dst2) {
	this->isLabelSet = false;
}

ILOC::ILOC(Common::ILOC_OperationType type, const std::string& label, const std::string& src1, const std::string& src2, const std::string& dst1, const std::string& dst2):
	type(type), label(label), src1(src1), src2(src2), dst1(dst1), dst2(dst2) {
	this->isLabelSet = true;
}

ILOC::ILOC(std::string& line) {
	// TODO
}

bool ILOC::hasLabel() {
	return this->isLabelSet;
}

void ILOC::setLabel(std::string lbl) {
	this->isLabelSet = true;
	this->label = lbl;
}

std::string ILOC::codeline() {
	std::string line;

	switch(this->type) {
	// NOP
	case Common::ILOC_NOP:
		line = "nop";
		break;

		// Operaciones aritméticas (solo con registradores)
	case Common::ILOC_ADD:
		line = "add " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_SUB:
		line = "sub " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_MULT:
		line = "mult " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_DIV:
		line = "div " + src1 + ", " + src2 + " => " + dst1;
		break;

		// Operaciones aritméticas (con inmediatos)
	case Common::ILOC_ADDI:
		line = "addI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_SUBI:
		line = "subI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_RSUBI:
		line = "rsubI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_MULTI:
		line = "multI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_DIVI:
		line = "divI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_RDIVI:
		line = "rdivI " + src1 + ", " + src2 + " => " + dst1;
		break;

		// Operaciones logicas
	case Common::ILOC_LSHIFT:
		line = "lshift " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_LSHIFTI:
		line = "lshiftI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_RSHIFT:
		line = "rshift " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_RSHIFTI:
		line = "rshiftI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_AND:
		line = "and " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_ANDI:
		line = "andI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_OR:
		line = "or " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_ORI:
		line = "orI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_XOR:
		line = "xor " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_XORI:
		line = "xorI " + src1 + ", " + src2 + " => " + dst1;
		break;

		// Operaciones sobre memoria
	case Common::ILOC_LOADI:
		line = "loadI " + src1 + " => " + dst1;
		break;
	case Common::ILOC_LOAD:
		line = "load " + src1 + " => " + dst1;
		break;
	case Common::ILOC_LOADAI:
		line = "loadAI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_LOADA0:
		line = "loadA0 " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_CLOAD:
		line = "cload " + src1 + " => " + dst1;
		break;
	case Common::ILOC_CLOADAI:
		line = "cloadAI " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_CLOADA0:
		line = "cloadA0 " + src1 + ", " + src2 + " => " + dst1;
		break;
	case Common::ILOC_STORE:
		line = "store " + src1 + " => " + dst1;
		break;
	case Common::ILOC_STOREAI:
		line = "storeAI " + src1 + " => " + dst1 + ", " + dst2;
		break;
	case Common::ILOC_STOREA0:
		line = "storeA0 " + src1 + " => " + dst1 + ", " + dst2;
		break;
	case Common::ILOC_CSTORE:
		line = "cstore " + src1 + " => " + dst1;
		break;
	case Common::ILOC_CSTOREAI:
		line = "cstoreAI " + src1 + " => " + dst1 + ", " + dst2;
		break;
	case Common::ILOC_CSTOREA0:
		line = "cstoreA0 " + src1 + " => " + dst1 + ", " + dst2;
		break;
	case Common::ILOC_I2I:
		line = "i2i " + src1 + " => " + dst1;
		break;
	case Common::ILOC_C2C:
		line = "c2c " + src1 + " => " + dst1;
		break;
	case Common::ILOC_C2I:
		line = "c2i " + src1 + " => " + dst1;
		break;
	case Common::ILOC_I2C:
		line = "i2c " + src1 + " => " + dst1;
		break;

		// Operaciones de flujo de control
	case Common::ILOC_JUMPI:
		line = "jumpI -> " + dst1;
		break;
	case Common::ILOC_JUMP:
		line = "jump  -> " + dst1;
		break;
	case Common::ILOC_CBR:
		line = "cbr " + src1 + " -> " + dst1 + ", " + dst2;
		break;
	case Common::ILOC_CMP_LT:
		line = "cmp_LT " + src1 + ", " + src2 + " -> " + dst1;
		break;
	case Common::ILOC_CMP_LE:
		line = "cmp_LE " + src1 + ", " + src2 + " -> " + dst1;
		break;
	case Common::ILOC_CMP_EQ:
		line = "cmp_EQ " + src1 + ", " + src2 + " -> " + dst1;
		break;
	case Common::ILOC_CMP_GE:
		line = "cmp_GE " + src1 + ", " + src2 + " -> " + dst1;
		break;
	case Common::ILOC_CMP_GT:
		line = "cmp_GT " + src1 + ", " + src2 + " -> " + dst1;
		break;
	case Common::ILOC_CMP_NE:
		line = "cmp_NE " + src1 + ", " + src2 + " -> " + dst1;
		break;
	}

	if (!this->label.empty()) {
		line = this->label + ": " + line;
	}

	return line;
}

//=============================================
// Static methods
//=============================================
void ILOC::initRegisters() {
	for (unsigned int i = 0; i < MAX_REGISTERS; i++) {
		ILOC::registersBeingUsed.at(i) = "";
	}
}

std::string* ILOC::getRegister(const std::string& identifierName) {
	int registerIndex;
	std::stringstream registerName;

	Dictionary::iterator registerPair = ILOC::registersByIdentifier.find(identifierName);
	if (registerPair != ILOC::registersByIdentifier.end()) {
		registerName << 'r' << registerPair->second;
	} else {
		for (unsigned int i = 0; i < MAX_REGISTERS; i++) {
			if (ILOC::registersBeingUsed.at(i).compare("") == 0) {
				ILOC::registersByIdentifier.insert(Dictionary::value_type(identifierName, i));
				ILOC::registersBeingUsed.at(i) = identifierName;
				registerIndex = i;
				break;
			}
		}
		registerName << 'r' << registerIndex;
	}

	return new std::string(registerName.str());
}

void ILOC::returnRegister(const std::string& registerName) {
	std::string rName = registerName;
	rName.erase(0, 1);
	int registerIndex = atoi(rName.c_str());
	std::string identifierName = ILOC::registersBeingUsed.at(registerIndex);
	ILOC::registersByIdentifier.erase(identifierName);
	ILOC::registersBeingUsed.at(registerIndex) = "";
}

const std::string ILOC::makeLabel() {
	std::stringstream labelName;
	labelCount++;
	labelName << 'L' << labelCount;
	return labelName.str();
}

