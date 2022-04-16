#include "cgi.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

inline man create_elem(const char* name, const char* sex,
	int age, const char* job, int income, const char* goal) {
	man m;
	strcpy_s(m.name, name);
	strcpy_s(m.sex, sex);
	m.age = age;
	strcpy_s(m.job, job);
	m.income = income;
	strcpy_s(m.goal, goal);

	return m;
}

//��������� ������ �������� � �������
void enqueue(queue& queue, const char* name, const char* sex,
	int age, const char* job, int income, const char* goal) {
	man newm = create_elem(name, sex, age, job, income, goal);
	elem* newel = new elem;
	newel->m = newm;
	if (!queue.head) {
		queue.head = newel;
		queue.tail = newel;
		queue.size = 1;
		return;
	}
	queue.tail->next = newel;
	queue.tail = newel;
	queue.size++;
}

//���������� �������� �� ������� 
bool dequeue(queue& queue, man& man) {
	if (queue.size == 0) {
		return false;
	}
	man = queue.head->m;
	elem* rem = queue.head;
	queue.head = queue.head->next;
	if (queue.size == 1) queue.tail = nullptr;
	queue.size--;
	delete rem;
	return true;
}

//�������� �������
void clear(queue& queue) {
	while (queue.size > 0) {
		elem* rem = queue.head;
		queue.head = queue.head->next;
		delete rem;
		queue.size--;
	}
	queue.tail = nullptr;
}

void Show(queue& queue) {
	man m;
	while (dequeue(queue, m)) {
		cout << "<div><b> " << m.name << " " << m.sex << " " << m.age <<
			" " << m.job << " " << m.income << " " << m.goal << " </b></div>";
	}
}

void load_data(char* s, queue& people_credit, queue& people_contribution)
{
	char name[50];
	char sex[50];
	int age;
	char job[50];
	int income;
	char goal[50];
	char* s_copy = new char[strlen(s) + 1];
	strcpy_s(s_copy, strlen(s) + 1, s);
	char* context;
	char* temp = s_copy;
	while (char* part = strtok_s(temp, "\n", &context))
	{
		sscanf_s(part, "%s %s %d %s %d %s",
			name, 50, sex, 50, &age, job, 50, &income, goal, 50);
		if (string(goal) == "������") enqueue(people_credit, name, sex, age, job, income, goal);
		else enqueue(people_contribution, name, sex, age, job, income, goal);
		temp = nullptr;
	}
	delete[] s_copy;
}


bool is_get()
{
	size_t realsize;
	char* value = new char[5];
	getenv_s(&realsize, value, 5, "REQUEST_METHOD");
	bool res = !_strcmpi(value, "GET");
	delete[] value;
	return res;
}

size_t get_content_length()
{
	size_t realsize;
	char* value = new char[11];
	getenv_s(&realsize, value, 11, "CONTENT_LENGTH");
	size_t size;
	if (!realsize) size = 0;
	else sscanf_s(value, "%d", &size);
	delete[] value;
	return size;
}

void get_form_data(char*& data)
{
	delete[] data;
	if (is_get())
	{
		size_t realsize;
		char* value = new char[65536];
		getenv_s(&realsize, value, 65536, "QUERY_STRING");
		data = new char[realsize + 1];
		strcpy_s(data, realsize + 1, value);
		delete[] value;
	}
	else
	{
		size_t buf_size = get_content_length();
		data = new char[buf_size + 1];
		fread_s(
			data,
			buf_size + 1,
			sizeof(char),
			buf_size,
			stdin
		);
		data[buf_size] = 0;
	}
}

void get_param_value(char*& value, const char* param_name, const char* data)
{
	delete[] value;
	value = nullptr;
	char* str = _strdup(data);
	char* tmp = str;
	char* cont;
	while (char* part = strtok_s(tmp, "&", &cont))
	{
		tmp = nullptr;
		char* val;
		char* key = strtok_s(part, "=", &val);
		if (!_strcmpi(param_name, key))
		{
			str_decode(value, val);
			//value = _strdup(val);
			delete[] str;
			return;
		}
	}
	delete[] str;
	value = new char[1];
	value[0] = 0;
}

void str_decode(char*& dec_str, const char* enc_str)
{
	char* res = new char[strlen(enc_str) + 1];
	int i = 0, j = 0;
	while (enc_str[i])
	{
		if (enc_str[i] == '+')
		{
			res[j] = ' ';
		}
		else
		{
			if (enc_str[i] == '%')
			{
				char ch[3] = { enc_str[i + 1], enc_str[i + 2], 0 };
				int c;
				sscanf_s(ch, "%X", &c);
				res[j] = c;
				i += 2;
			}
			else
			{
				res[j] = enc_str[i];
			}
		}
		i++;
		j++;
	}
	res[j] = 0;
	size_t len = strlen(res) + 1;
	delete[] dec_str;
	dec_str = new char[len];
	strcpy_s(dec_str, len, res);
	delete[] res;
}