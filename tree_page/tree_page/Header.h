#pragma once
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;


/// ��������� ��� �������� ����� ������
struct node
{
	/// �������� �������� (�������������� ����)
	float value;
	string name;
	/// ���������� ��������������� �������� � �������� ������ (�������������� ����)
	int count = 1;
	/// ������ ���������, � ������ � ������ ����
	int height = 1;
	/// ��������� �� ����� ��������� (��������� ����)
	node* left = nullptr;
	/// ��������� �� ������ ��������� (��������� ����)
	node* right = nullptr;
};
/// ��������� ��� �������� ���������� � ������ � �����
struct tree
{
	/// ������, ������������ ������
	node* root = nullptr;
	/// ����� ����� ��������� � ������
	size_t elem_count = 0;
};
/// ��������� ��� �������� ��������� �������
struct elem
{
	/// �������������� ����
	node* node;
	/// ��������� ����
	elem* next = nullptr;
};
/// ��������� ��� ������ � ��������, �������� ��������� �� �� ������ � �����
struct queue
{
	/// ������ ������� ������� (������)
	elem* head = nullptr;
	/// ��������� ������� ������� (�����)
	elem* tail = nullptr;
	/// ���������� ��������� � �������
	size_t size = 0;
};


/// ���������� �������� � �������
void enqueue(queue& queue, node* tree_node);
/// ���������� �������� �� �������
bool dequeue(queue& queue, node*& tree_node);
/// ������� �������
void clear(queue& queue);


/// ������� ���������� �������� � ������
void add_to_tree(tree& tree, float value, string name, bool type);
/// ������� ������ �������� � ������
void find_in_tree(const node* root, string letter, bool& f);
/// ������� �������� ������
/// ����� ������ ������. ���������� ������� (NLR)
queue prefix_traverse(tree tree);
/// ����� ������ ������. ��������� �������. (LNR)
queue infix_traverse(tree tree);
/// ����� ������ ������. ����������� ������� (LRN)
queue postfix_traverse(tree tree);
/// ����� ������ �����
queue wide_traverse(tree tree, bool include_empty = true);


bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);