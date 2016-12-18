//-
#include "postfix.h"
#include "stack.h"
#include <iostream>
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi (преобразовать символы к типу int)
using namespace std;

string postfix::toPostfix()
{
	char result[MaxSize];
	int result_pos = 0;
	stack stack_op(MaxSize);
	for (unsigned int i = 0; i < infx.length(); i++)
	{
		//--1--
		if ((infx[i] != '(') && (infx[i] != ')') && (infx[i] != '+') && (infx[i] != '-') && (infx[i] != '*') && (infx[i] != '/'))
		{
			result[result_pos] = infx[i];
			result_pos++;
			result[result_pos] = '\0';
		}
		//--2--
		if (infx[i] == '(') stack_op.push(infx[i]);
		//--3--                                            
		if (infx[i] == ')')
		{
			while (stack_op.peek() != '(')//пока
			{
				result[result_pos] = stack_op.pop();
				result_pos++;
				result[result_pos] = '\0';
			}
			stack_op.pop();
		}
		//-----
		if ((infx[i] == '+') || (infx[i] == '-') || (infx[i] == '*') || (infx[i] == '/'))
		{
			//--a--
			if (stack_op.isEmpty() || stack_op.peek() == '(') stack_op.push(infx[i]);
			//--b--
			else if (priority(infx[i]) > priority(stack_op.peek())) stack_op.push(infx[i]);
			//--c--
			else
			{
				while (!stack_op.isEmpty() && priority(infx[i]) <= priority(stack_op.peek()))
				{
					result[result_pos] = stack_op.pop();
					result_pos++;
					result[result_pos] = '\0';
				}
				stack_op.push(infx[i]);
				//-----
			}
		}

	}
	//--4--
	while (stack_op.isEmpty() == 0)//пока
	{
		result[result_pos] = stack_op.pop();
		result_pos++;
		result[result_pos] = '\0';
	}
	//-----
	postfx = result;
	return postfx;
}

double postfix::calculate()
{
	char a[MaxSize];
	double b[MaxSize];
	int flag;
	double k;

	stack stack(MaxSize);
	for (unsigned int i = 0; i < postfx.length(); i++)
	{
		//--a--
		if (postfx[i] != '+' && postfx[i] != '-' && postfx[i] != '*' && postfx[i] != '/')
		{
			flag = 0;
			a[i] = postfx[i];
			for (int j = 0; j < i; j++)
				if (postfx[i] == a[j])
				{
					flag = 1;
					stack.push(b[j]);
					break;
				}

			if (flag == 0)
			{
				char tmp[MaxSize];
				tmp[0] = postfx[i];
				tmp[1] = '\0';
				if ( isdigit(tmp[0]) ) b[i] = atoi(tmp); // преобразовать символы к типу int
				else
				{
				cout << postfx[i] << "=";
				cin >> k;
				b[i] = k;
				}
				stack.push(b[i]);
			}

		}
		else
			//--b--
		{
			if (postfx[i] == '+')
			{
				double tmp1 = stack.pop();
				double tmp11 = stack.pop();
				stack.push(tmp11 + tmp1);
			}
			if (postfx[i] == '-')
			{
				double tmp1 = stack.pop();
				double tmp11 = stack.pop();
				stack.push(tmp11 - tmp1);
			}
			if (postfx[i] == '/')
			{
				double tmp1 = stack.pop();
				double tmp11 = stack.pop();
				stack.push(tmp11 / tmp1);
			}
			if (postfx[i] == '*')
			{
				double tmp1 = stack.pop();
				double tmp11 = stack.pop();
				stack.push(tmp11 * tmp1);
			}
		}

	}

	return stack.pop();;
}