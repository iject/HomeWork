#pragma once

/// ��������� ��� ���������� ������
struct elem
{
	int a; /// ���� ��� �������� ������
	elem* next = nullptr; /// ��������� �� ��������� �������.
};

/// ������� ��� ���������� �������� � ����� ������
void add(elem*& list, int data);

/// ������� ��� ���������� �������� �� ��������� ����� � ������
/// (���� � ������ ��� ������ ������, ������� ����������� � ���
/// ������ ��� �����, � ����������� �� ����, ��� �����).
void insert(elem*& list, int data, int position);

/// ������� ������ �������� �� ��� ������ (�������) � ������
const int* get(const elem* list, int position);

/// ����������� ���������� ��������� ������
int count(const elem* list);

/// ������� �������� �������� �� ��� �������
bool remove(elem*& list, int position);

/// ������� �������� ������
void clear(elem*& list);

/// ������� ������ ������
void show_list(elem* list);

void r_list(const char* name, elem*& list);

void w_list(const char* name, elem*& list);

bool not_empty(const char* name);

bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);
