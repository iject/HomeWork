#pragma once
struct elem
{
	char value;
	elem* next = nullptr;
};

//���������� � ����� �������� 

void push(elem*& stack, char value);

//������� ��������� ������� 

bool pop(elem*& stack, char& value);

//��������� ��-�� � ������� �����

char peek(elem*& stack);

//����� �� ����� 

void ShowStack(elem*& stack);