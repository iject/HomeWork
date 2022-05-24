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
void add(list2& list, int data);
/// ������� ��� �������� �������� �� ������ �� ��� �������
bool remove(list2& list, int position);
/// ������� ��������� �������� ������ �� �������
const int* get(list2 list, int position);
void show_list(const list2& list, bool reversed = 0);
/// ������� ������� ������
void clear(list2& list);