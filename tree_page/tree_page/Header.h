#pragma once
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;


/// Структура для хранения узлов дерева
struct node
{
	/// Хранимое значение (информационное поле)
	float value;
	string name;
	/// Количество соответствующих значений в исходном наборе (информационное поле)
	int count = 1;
	/// Высота поддерева, с корнем в данном узле
	int height = 1;
	/// Указатель на левое поддерево (ссылочное поле)
	node* left = nullptr;
	/// Указатель на правое поддерево (ссылочное поле)
	node* right = nullptr;
};
/// Структура для хранения информации о дереве в целом
struct tree
{
	/// Корень, определяющий дерево
	node* root = nullptr;
	/// Общее число элементов в дереве
	size_t elem_count = 0;
};
/// Структура для хранения элементов очереди
struct elem
{
	/// Информационное поле
	node* node;
	/// Ссылочное поле
	elem* next = nullptr;
};
/// Структура для работы с очередью, хранящая указатели на ее начало и конец
struct queue
{
	/// Первый элемент очереди (голова)
	elem* head = nullptr;
	/// Последний элемент очереди (хвост)
	elem* tail = nullptr;
	/// Количество элементов в очереди
	size_t size = 0;
};


/// Добавление элемента в очередь
void enqueue(queue& queue, node* tree_node);
/// Извлечение элемента из очереди
bool dequeue(queue& queue, node*& tree_node);
/// Очистка очереди
void clear(queue& queue);


/// Функция добавления элемента в дерево
void add_to_tree(tree& tree, float value, string name, bool type);
/// Функция поиска элемента в дереве
void find_in_tree(const node* root, string letter, bool& f);
/// Функция удаления дерева
/// Обход дерева вглубь. Префиксный вариант (NLR)
queue prefix_traverse(tree tree);
/// Обход дерева вглубь. Инфиксный вариант. (LNR)
queue infix_traverse(tree tree);
/// Обход дерева вглубь. Постфиксный вариант (LRN)
queue postfix_traverse(tree tree);
/// Обход дерева вширь
queue wide_traverse(tree tree, bool include_empty = true);


bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);