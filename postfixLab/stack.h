#pragma once
#include <cstddef>

const int MaxSize = 100;

class stack
{
protected:
	int *pMem;
	int size;
	int count;
public:
	stack(int len = 10);
	~stack();
	bool isEmpty();
	bool isFull();
	void push(const int &val);//add
	int pop();//показать и удалить
	int peek();//view
};