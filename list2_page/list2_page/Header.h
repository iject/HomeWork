#pragma once
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

/// ��������� ��� �������� ��������� ������
struct elem {
	/// �������� ��������
	int x;
	/// �����
	int n;
	/// ��������� �� ��������� ������� ������
	elem* next = nullptr;
	/// ��������� �� ���������� ������� ������
	elem* prev = nullptr;
};
/// ��������� ��� ����������� ����������, ������������ ���� ���������� ������.
/// ������������� ��� ���������� ������������� ������ � ��������� ��������
struct list2 {
	/// ��������� �� ������ ������� ������
	elem* first = nullptr;
	/// ��������� �� ��������� ������� ������
	elem* last = nullptr;
	/// ���� ��� �������� ������� ������
	int count = 0;
};

/// ������� ��� ���������� �������� � ������
void add(list2& list, int data, int n);
/// ������� ��� �������� �������� �� ������ �� ��� �������
bool remove(list2& list, int position);
/// ������� ��������� �������� ������ �� �������
const int* get(list2 list, int position);
const int* get_n(list2 list, int position);
/// ������� ������� ������
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
