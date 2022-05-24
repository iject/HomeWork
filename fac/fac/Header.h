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
void add(list2& list, int data);
/// Функция для удаления элемента из списка по его индексу
bool remove(list2& list, int position);
/// Функция получения элемента списка по индексу
const int* get(list2 list, int position);
void show_list(const list2& list, bool reversed = 0);
/// Функция очистки списка
void clear(list2& list);