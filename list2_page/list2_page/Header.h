#pragma once
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

/// Структура для хранения элементов списка
struct elem {
	/// Хранимое значение
	int x;
	/// Номер
	int n;
	/// Указатель на следующий элемент списка
	elem* next = nullptr;
	/// Указатель на предыдущий элемент списка
	elem* prev = nullptr;
};
/// Структура для объединения указателей, определяющих один двусвязный список.
/// Предназначена для облегчения использования списка в сторонних функциях
struct list2 {
	/// Указатель на первый элемент списка
	elem* first = nullptr;
	/// Указатель на последний элемент списка
	elem* last = nullptr;
	/// Поле для хранения размера списка
	int count = 0;
};

/// Функция для добавления элемента в список
void add(list2& list, int data, int n);
/// Функция для удаления элемента из списка по его индексу
bool remove(list2& list, int position);
/// Функция получения элемента списка по индексу
const int* get(list2 list, int position);
const int* get_n(list2 list, int position);
/// Функция очистки списка
void clear(list2& list);
void show_list(const list2& list, bool reversed = false);
void strcut_p(char* a, int x, char*& s);
void razb_group(list2& list, char a[30], char b[30], int& max);
void sum(list2& list, int max, string*& mas);
void rev(char*& str);


bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);
