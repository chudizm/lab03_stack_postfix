#include "postfix.h"
#include <string>
#include <iostream>
using namespace std;

void main()
{
	double res;
	string exStr,exPfx;
	cout << "Enter the expression: " << endl;
	cin >> exStr;
	postfix expr(exStr);
	exPfx = expr.toPostfix();
	cout << "Postfix expression:" << endl << exPfx << endl;
	system("pause");
	res = expr.calculate();
	cout << endl << "Result: " << res << endl;
	system("pause");
}