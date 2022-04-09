#pragma once
struct elem
{
	char value;
	elem* next = nullptr;
};

//добавление в конец элемента 

void push(elem*& stack, char value);

//извлечь последний элемент 

bool pop(elem*& stack, char& value);

//получение эл-та с вершины стека

char peek(elem*& stack);

//вывод на экран 

void ShowStack(elem*& stack);