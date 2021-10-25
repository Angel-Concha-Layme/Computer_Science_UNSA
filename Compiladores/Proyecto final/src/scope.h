#ifndef SCOPE_H
#define SCOPE_H

#include <deque>
#include <vector>
#include <tr1/unordered_map>
#include "tree/common.h"
#include "tree/node.h"
#include "tree/vardeclarationnode.h"
#include "symbol.h"

class Scope {

public:
	Scope();
	static void pushScope(Node * newScopeNode);
	static Node* popScope();
	static Node* getScope();
	static Node* getScope(const std::string& token);
	static bool isTokenInScopes(const std::string& token);
	static bool isTokenInClosestScope(const std::string& token);
	static void addSymbol(Symbol* symbol);
	static Symbol* getSymbol(const std::string& token);
	static int scopeCount();
	static void setParams(const std::string &funcName, std::vector<Node*>* params);

private:
	static std::deque<Node*> scopes;
	static int count;
};


#endif // SCOPE_H
