#pragma once
#include "stack.h"

stack::stack(int len) 
{
	if ((len<1) || (len>MaxSize)) throw (len);
	size = len;
	count = 0;
	pMem = new int[size];// pMem[0] and pMem[1]
}

stack::~stack() 
{
	delete[]pMem;
	pMem = NULL;
}

bool stack::isEmpty() 
{
	return(count == 0);
}

bool stack::isFull() 
{
	return (count == size);
}

void stack::push(const int &val) 
{
	if (isFull())  throw (count);
	pMem[count] = val;
	count++;
}


int stack::pop() 
{
	if (isEmpty()) throw (count);
	count--;
	return pMem[count];
}


int stack::peek() 
{
	if (isEmpty()) throw (count);
	return pMem[count - 1];
}