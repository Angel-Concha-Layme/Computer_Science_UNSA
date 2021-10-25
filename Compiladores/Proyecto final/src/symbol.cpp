#include "symbol.h"

Symbol::Symbol(const std::string& text, const Common::TokenType& tokenType): text(text), tokenType(tokenType) {}

Symbol::Symbol(const std::string& text, const Common::TokenType& tokenType, const Common::DataType& dataType): text(text), tokenType(tokenType), dataType(dataType) {}

Symbol::Symbol(const std::string& text, const Common::DataType& dataType): text(text), dataType(dataType) {}

std::string Symbol::getText() {
	return text;
}

void Symbol::setText(const std::string &value) {
	this->text = value;
}

Common::DataType Symbol::getDataType() const {
	return dataType;
}

void Symbol::setDataType(const Common::DataType &value) {
	this->dataType = value;
}

Common::TokenType Symbol::getTokenType() const {
	return tokenType;
}

void Symbol::setTokenType(const Common::TokenType &value) {
	this->tokenType = value;
}


std::string Symbol::getValue() const {
	return value;
}

void Symbol::setValue(const std::string& value) {
	this->value = value;
}

void Symbol::setOffset(int os) {
	this->offset = os;
}

int Symbol::getOffset() {
	return offset;
}

int Symbol::getDataTypeSize(Common::DataType dt) {
	switch(dt) {
		case Common::BOOL:
			return DataSize::BOOL;
			break;
		case Common::INT:
			return DataSize::INT;
			break;
		case Common::CHAR:
			return DataSize::CHAR;
			break;
		case Common::FLOAT:
			return DataSize::FLOAT;
			break;
		default:
			return 0;

	}
}

std::vector<Common::DataType> *Symbol::getParams()
{
	return params;
}

void Symbol::setParams(std::vector<Common::DataType> *value)
{
	params = value;
}
