#pragma once

/// Структура для реализации списка
struct elem
{
	int a; /// Поле для хранения данных
	elem* next = nullptr; /// Указатель на следующий элемент.
};

/// Функция для добавления элемента в конец списка
void add(elem*& list, int data);

/// Функция для добавления элемента на указанное место в списке
/// (если в списке нет такого номера, элемент добавляется в его
/// начало или конец, в зависимости от того, что ближе).
void insert(elem*& list, int data, int position);

/// Функция поиска элемента по его номеру (позиции) в списке
const int* get(const elem* list, int position);

/// Определение количества элементов списка
int count(const elem* list);

/// Функция удаления элемента по его позиции
bool remove(elem*& list, int position);

/// Функция удаления списка
void clear(elem*& list);

/// Функция вывода списка
void show_list(elem* list);

void r_list(const char* name, elem*& list);

void w_list(const char* name, elem*& list);

bool not_empty(const char* name);

bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);
