#include "operationnode.h"
#include <stdio.h>

OperationNode::OperationNode(const Common::OperationType& operationType, Node* leftSide, Node* rightSide):
	ExpressionNode("Expresion operation", Common::EX_OPERATION), operationType(operationType) {

	Common::DataType dataTypeExprLeft, dataTypeExprRight;


	if (leftSide != NULL) {
		this->addChild(leftSide);
		ExpressionNode* left = dynamic_cast<ExpressionNode*>(leftSide);
		dataTypeExprLeft = left->getDataType();
	}


	if (rightSide != NULL) {
		this->addChild(rightSide);
		ExpressionNode* right = dynamic_cast<ExpressionNode*>(rightSide);
		dataTypeExprRight = right->getDataType();
	}

	if (leftSide != NULL && rightSide != NULL) {
		if (dataTypeExprLeft != dataTypeExprRight)
			yyerror("tipos diferentes de expresion.");
		else
			this->dataType = dataTypeExprLeft;
	} else if (leftSide != NULL)
		this->dataType = dataTypeExprLeft;



	this->generateILOCCode(NULL);
}

void OperationNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 2) {
		this->children->at(0)->printSourceCode("");
		fprintf(this->flexOut, "%s", " ");
		fprintf(this->flexOut, "%s", this->operationTypeToString(this->operationType).c_str());
		fprintf(this->flexOut, "%s", " ");
		this->children->at(1)->printSourceCode("");
	} else if (this->children->size() == 1) {
		if (this->operationType == Common::OP_PAREN) {
			fprintf(this->flexOut, "%s", "(");
			this->children->at(0)->printSourceCode("");
			fprintf(this->flexOut, "%s", ")");
		} else if (this->operationType == Common::OP_SUB) {
			fprintf(this->flexOut, "%s", "-");
			this->children->at(0)->printSourceCode("");
		}
	}
}

void OperationNode::generateILOCCode(Node* context) {
	ILOC* instruction;
	if (this->children->size() == 2) {
		ExpressionNode* left = dynamic_cast<ExpressionNode*>(this->children->at(0));
		ExpressionNode* right = dynamic_cast<ExpressionNode*>(this->children->at(1));

		std::vector<ILOC*> l = left->getInstructions();
		std::vector<ILOC*> r = right->getInstructions();

		switch (this->operationType) {
			case Common::OP_SUM: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_SUM_REG");
				instruction = new ILOC(Common::ILOC_ADD, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_SUB: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_SUB_REG");
				ILOC* instruction = new ILOC(Common::ILOC_SUB, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_MULT: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_MULT_REG");
				ILOC* instruction = new ILOC(Common::ILOC_MULT, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_DIV: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_DIV_REG");
				ILOC* instruction = new ILOC(Common::ILOC_DIV, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_AND: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				std::string labelTrue = ILOC::makeLabel();
				std::string labelFalse = ILOC::makeLabel();
				ILOC* instructionShortCircuit = new ILOC(Common::ILOC_CBR, left->getLastRegister(), "", labelTrue, labelFalse);
				ILOC* instructionNopTrue = new ILOC(Common::ILOC_NOP, labelTrue, "nop", "", "", "");
				this->addInstruction(instructionShortCircuit);
				this->addInstruction(instructionNopTrue);
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_AND_REG");
				ILOC* instruction = new ILOC(Common::ILOC_AND, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC* instructionNopFalse = new ILOC(Common::ILOC_NOP, labelFalse, "nop", "", "", "");
				this->addInstruction(instruction);
				this->addInstruction(instructionNopFalse);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_OR: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				std::string labelTrue = ILOC::makeLabel();
				std::string labelFalse = ILOC::makeLabel();
				ILOC* instructionShortCircuit = new ILOC(Common::ILOC_CBR, left->getLastRegister(), "", labelTrue, labelFalse);
				ILOC* instructionNopFalse = new ILOC(Common::ILOC_NOP, labelFalse, "nop", "", "", "");
				this->addInstruction(instructionShortCircuit);
				this->addInstruction(instructionNopFalse);
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_OR_REG");
				ILOC* instruction = new ILOC(Common::ILOC_OR, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC* instructionNopTrue = new ILOC(Common::ILOC_NOP, labelTrue, "nop", "", "", "");
				this->addInstruction(instruction);
				this->addInstruction(instructionNopTrue);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_LESS: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_CMP_LT_REG");
				ILOC* instruction = new ILOC(Common::ILOC_CMP_LT, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_GREATER: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_CMP_GT_REG");
				ILOC* instruction = new ILOC(Common::ILOC_CMP_GT, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_LE: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_CMP_LE_REG");
				ILOC* instruction = new ILOC(Common::ILOC_CMP_LE, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_GE: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_CMP_GE_REG");
				ILOC* instruction = new ILOC(Common::ILOC_CMP_GE, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_EQUAL: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_CMP_EQ_REG");
				ILOC* instruction = new ILOC(Common::ILOC_CMP_EQ, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_NEQUAL: {
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->instructions.insert( this->instructions.end(), r.begin(), r.end() );
				std::string* operationRegister = ILOC::getRegister("@EX_CMP_NEQ_REG");
				ILOC* instruction = new ILOC(Common::ILOC_CMP_NE, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				this->addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			default:
				break;
		}
	} else if (this->children->size() == 1) {
		ExpressionNode* left = dynamic_cast<ExpressionNode*>(this->children->at(0));
		switch (this->operationType) {
			case Common::OP_PAREN: {
				std::vector<ILOC*> l = left->getInstructions();
				this->instructions.insert( this->instructions.end(), l.begin(), l.end() );
				this->setLastRegister(left->getLastRegister());
				break;
			}
			default:
				break;
		}
	}
}
