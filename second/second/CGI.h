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

//удаляет эл-т с вершины стека

void delete_el(elem*& stack);

//получение эл-та с вершины стека

char peek(elem*& stack);

bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);
