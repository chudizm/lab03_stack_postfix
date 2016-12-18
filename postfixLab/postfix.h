#pragma once
#include <string>
#include "stack.h"
using namespace std;

class postfix
{
	string infx;
	string postfx;
public:
	postfix(string val)
	{
		infx = val;
	}
	int priority(char val)
	{
		if ((val == '*') || (val == '/')) return 2;
		if ((val == '+') || (val == '-')) return 1;
		return -1;
	}
	string getInfix() { return infx; }
	string getPostfix() { return postfx; }
	string toPostfix();
	double calculate();
};