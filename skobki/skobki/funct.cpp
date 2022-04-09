#include<iostream>
#include "Header.h"
using namespace std;

void push(elem*& stack, char value)
{
	elem* newel = new elem;
	newel->value = value;

	if (!stack)
	{
		stack = newel;
		return;
	}

	newel->next = stack;
	stack = newel;
}

//извлечь последний элемент 

bool pop(elem*& stack, char& value)
{
	if (!stack)
	{
		return false;
	}

	elem* cur = stack;
	value = stack->value;
	stack = stack->next;
	delete cur;
	return true;
}

void delete_el(elem*& stack)
{
	if (!stack)
	{
		return;
	}

	elem* cur = stack;
	stack = stack->next;
	delete cur;
}

char peek(elem*& stack)
{
	if (!stack)
	{
		return 'e';
	}

	return stack->value;
}

//вывод на экран 

void ShowStack(elem*& stack) {

	while (stack) {

		char value;

		if (pop(stack, value)) {
			cout << value << " ";
		}

	}

}