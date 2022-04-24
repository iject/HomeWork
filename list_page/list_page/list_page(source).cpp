#include "list_page.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

void add(elem*& first, int data)
{
	elem* newel = new elem; // Создание элемента списка
	newel->a = data;

	if (count(first) > 0)
	{
		elem* curr = first;// Указатель на текущий элемент
		if (curr && (curr->a == data)) return;
		while (curr->next)
		{
			curr = curr->next;
			if (curr->a == data) return;
		}
	}


	if (first) // Определение наличия списка
	{
		// Список есть, добавляем элемент в конец.
		// Для этого пробегаем до последнего элемента списка.
		elem* curr = first; // Устанавливаем указатель на первый элемент
		// Пока существует следующий элемент в списке
		while (curr->next)
		{
			// Перемещаем указатель на следующий элемент
			curr = curr->next;
		}
		//Указатель curr теперь находится на последнем элементе
		// устанавливаем у текущего элемента указатель next на новый элемент
		curr->next = newel;
	}
	else
	{
		// Списка раньше не было. Значит новый элемент будет первым
		first = newel;
	}
}

void insert(elem*& first, int data, int pos)
{
	// Добавление элемента в заданную позицию в списке.
	// Если будет указано отрицательное или нулевое значение,
	// элемент станет первым.
	// Если будет указано значение, большее или равное длине списка,
	// элемент станет последним.
	elem* newel = new elem; // Создание элемента списка
	newel->a = data;
	// Как и в функции add, проверяем наличие списка.
	// Кроме того, проверяем, что позиция вставки >0, иначе
	// новый элемент также оказывается первым.


	if (count(first) > 0)
	{
		elem* curr = first;// Указатель на текущий элемент
		if (curr && (curr->a == data)) return;
		while (curr->next)
		{
			curr = curr->next;
			if (curr->a == data) return;
		}
	}


	if (first && pos > 0)
	{
		elem* curr = first;// Указатель на текущий элемент

		int p = 0;// Счетчик элементов
		while (curr->next && p < pos - 1)
		{
			// Цикл работает либо пока не дойдем до последнего элемента,
			// либо пока не дойдем до позиции, предшествующей позиции вставки
			curr = curr->next;
			p++;
		}
		// curr теперь указывает на элемент, после которого нужно размещать новый
		// Размещаем новый элемент в списке
		newel->next = curr->next;
		curr->next = newel;
	}
	else
	{
		newel->next = first;
		first = newel;
	}
}

void r_list(const char* name, elem*& list)
{
	string s;
	ifstream f;
	f.open(name);
	if (f.is_open())
	{
		while (!f.eof())
		{
			f >> s;
			add(list, stoi(s));
		}
	}
	f.close();
}

void w_list(const char* name, elem*& list)
{
	string s;
	ofstream f;
	f.open(name);
	if (f.is_open())
	{
		for (int i = 0; i < count(list); i++)
		{
			f << *get(list, i) << " ";
		}
	}
	f.close();
}

bool not_empty(const char* name)
{
	ifstream f;
	f.open(name);
	if (f.is_open())
	{
		f.seekg(0, ios::end);
		if (f.tellg() == 0) return false;
		else true;
	}
	f.close();
}

const int* get(const elem* first, int pos)
{
	// Элемента с таким номером не существует
	if (pos < 0 || !first) return nullptr;
	// Находим элемент с указанным номером
	int p = 0;
	elem* curr = (elem*)first;
	while (curr && p < pos)
	{
		curr = curr->next;
		p++;
	}
	// В этот момент curr либо указывает на нужный элемент списка, либо равен nullptr,
	// если элемента с нужным номером не существовало
	if (curr)
	{
		return &curr->a; // Элемент найден. Возвращаем указатель на значение
	}
	// Элемент не найден
	return nullptr;
}

int count(const elem* first)
{
	// Счетчик элементов списка
	int cnt = 0;
	elem* curr = (elem*)first;
	while (curr)// Перебираем все элементы
	{
		cnt++;
		curr = curr->next;
	}
	return cnt;
}

bool remove(elem*& first, int pos) {
	// Элемента с таким номером не существует – удалять нечего
	if (pos < 0 || !first) return false;
	if (pos == 0) { // Если удаляется первый элемент, меняем указатель на начало списка
		elem* rem = first;
		first = first->next;
		delete rem;
		return true;
	}
	// Удаляется элемент не из начала.
	// Находим элемент, предшествующий элементу с указанным номером
	int p = 0;
	elem* curr = first;
	while (curr->next && p < pos - 1) {
		curr = curr->next;
		p++;
	}

	// Определяем причину выхода из цикла:
	if (curr->next)
	{
		// Искомая позиция найдена, можно удалять следующий относительно curr элемент.
		elem* rem = curr->next;
		curr->next = curr->next->next;
		delete rem;
		return true;
	}
	// Элемент не найден.
	return false;
}

void clear(elem*& first)
{
	while (first)
	{
		// Запоминаем элемент для удаления
		elem* del = first;
		// Начало списка смещаем на следующий элемент
		first = first->next;
		// Удаляем сохраненный элемент.
		delete del;
	}
}

void show_list(elem* list)
{
	elem* curr = list;
	
	if (!curr) cout << "<div><b>" << "EMPTY LIST" << "</b></div>" << endl;
	else while (curr)
	{
		cout << "<b>" << curr->a << " " << "</b>";
		curr = curr->next;
	}
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