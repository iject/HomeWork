#include "Header.h"

void add(list2& list, int data, int n)
{
	// Создание нового элемента списка
	elem* newel = new elem;
	newel->x = data;
	newel->n = n;
	// При вставке элемента увеличиваем длину списка
	list.count++;
	// Проверка наличия списка
	if (!list.first)
	{
		// Если списка еще не было, новый элемент будет первым
		list.first = list.last = newel;
	}
	else
	{
		newel->next = list.first;
		list.first->prev = newel;
		list.first = newel;
	}
}

bool remove(list2& list, int pos)
{
	if (pos < 0 || pos >= list.count)
		return false; // Такого элемента нет.
	list.count--; // Количество элементов будет уменьшено.
	if (pos == 0)
	{
		// Удаляется первый элемент
		elem* rem = list.first;
		// Изменяем указатель на начало списка
		list.first = list.first->next;
		if (list.first) list.first->prev = nullptr;
		delete rem;
		return true;
	}
	if (pos == list.count)
	{
		// Удаляется последний элемент
		elem* rem = list.last;
		// Изменяем указатель на конец списка
		list.last = list.last->prev;
		list.last->next = nullptr;
		delete rem;
		return true;
	}
	// Удаляется элемент из середины списка
// Определяем направление обхода списка
	bool frw = (pos <= list.count / 2);
	int p = 1;
	elem* curr;
	if (frw) {
		// Если удаляемый элемент из первой половины, пробегаем от начала...
		curr = list.first->next;
	}
	else {
		// ...иначе - с конца.
		pos = list.count - pos;
		curr = list.last->prev;
	}
	// Пробегаем по списку до искомого элемента, либо до конца списка
	while (p < pos) {
		// Шагаем вперед или назад в зависимости от направления движения по списку
		curr = frw ? curr->next : curr->prev;
		p++;
	}
	// Корректируем указатель у предыдущего элемента
	curr->prev->next = curr->next;
	// Корректируем указатель у следующего элемента
	curr->next->prev = curr->prev;
	// Удаляем текущий элемент
	delete curr;
	return true;
}

const int* get(list2 list, int pos) {
	if (!list.first || pos < 0 || pos >= list.count)
		return nullptr; // Такого элемента нет
	if (!pos)return &list.first->x; // Возвращаем значение первого элемента
	if (pos == list.count - 1)
		return &list.last->x; // Возвращаем значение последнего элемента
		// Иначе ищем элемент с нужным номером
	int p = 1;
	// Определяем предпочтительное направление поиска
	bool fwd = pos <= list.count / 2;
	elem* curr;
	// Находим стартовый элемент
	if (fwd)
		curr = list.first->next;
	else {
		curr = list.last->prev;
		// Корректируем номер искомого элемента в зависимости от направления поиска
		pos = list.count - pos - 1;
	}
	while (curr && p < pos) {
		p++;
		// Переходим вперед или назад в зависимости от направления поиска
		curr = fwd ? curr->next : curr->prev;
	}
	// Здесь указатель находится на искомом элементе
	return &curr->x;
}

const int* get_n(list2 list, int pos) {
	if (!list.first || pos < 0 || pos >= list.count)
		return nullptr; // Такого элемента нет
	if (!pos)return &list.first->n; // Возвращаем значение первого элемента
	if (pos == list.count - 1)
		return &list.last->n; // Возвращаем значение последнего элемента
		// Иначе ищем элемент с нужным номером
	int p = 1;
	// Определяем предпочтительное направление поиска
	bool fwd = pos <= list.count / 2;
	elem* curr;
	// Находим стартовый элемент
	if (fwd)
		curr = list.first->next;
	else {
		curr = list.last->prev;
		// Корректируем номер искомого элемента в зависимости от направления поиска
		pos = list.count - pos - 1;
	}
	while (curr && p < pos) {
		p++;
		// Переходим вперед или назад в зависимости от направления поиска
		curr = fwd ? curr->next : curr->prev;
	}
	// Здесь указатель находится на искомом элементе
	return &curr->n;
}

void clear(list2& list)
{
	// Функция очистки двусвязного списка практически не отличается от таковой
	// для списка односвязного.
	elem* rem;
	while (list.first)
	{
		rem = list.first;
		list.first = list.first->next;
		delete rem;
	}
	list.last = nullptr; // Корректируем указатель на последний элемент
	list.count = 0; // Корректируем количество элементов списка
}

void show_list(const list2& list, bool reversed)
{
	// Устанавливаем указатель на начало или конец списка в зависимости от порядка
	// вывода его элементов, определяемого параметром reversed
	elem* curr = reversed ? list.last : list.first;
	if (!curr) cout << "<div><b>" << "Список пуст" << "</b></div>" << endl;// Список пуст
	// Пробегаем по всем элементам списка и выводим значения
	else while (curr)
	{
		elem* cmp = reversed ? list.first : list.last;
		cout << "<b>" << curr->x << ((curr == cmp) ? "\n" : " ") << "</b>";
		curr = reversed ? curr->prev : curr->next;
	}
}


void strcut_p(char* a, int x, char*& s)
{
	for (int i = 0; i < 9; x++, i++)
	{
		s[i] = a[x];
		if (a[x] == '\0') return;
	}
	s[9] = '\0';
}

void rev(char*& str) {

	int length = strlen(str);
	char temp;
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void razb_group(list2& list, char a[30], char b[30], int& max)
{
	int a_size = strlen(a);
	int b_size = strlen(b);

	rev(a);
	rev(b);

	int x = 0;
	char* s = new char[10];

	for (int i = 0; i <= a_size / 9; i++)
	{
		strcut_p(a, x, s);
		rev(s);
		if (strlen(s) > 0)
		{
			add(list, stoi(s), i);
			max = i;
		}
		x += 9;
	}

	x = 0;
	for (int i = 0; i <= b_size / 9; i++)
	{
		strcut_p(b, x, s);
		rev(s);
		if (strlen(s) > 0)
		{
			add(list, stoi(s), i);
			if (i > max) max = i;
		}
		x += 9;
	}
}

void sum(list2& list, int max, string*& mas)
{
	int count = 0;
	int flag = 0;

	while (count <= max)
	{
		int sum = 0;
		int a_in = -1, b_in = -1;

		for (int i = 0; i < list.count; i++)
		{
			if (*get_n(list, i) == count && a_in == -1) a_in = i;
			if (*get_n(list, i) == count && a_in != -1 && a_in != i) b_in = i;
		}

		if (b_in != -1)
		{
			char a[10];
			char b[10];
			char sum_s[11];
			int a_i = *get(list, a_in);
			int b_i = *get(list, b_in);
			//int max_len;
			sum = a_i + b_i + flag;
			/*sprintf_s(a, "%d", a_i);
			sprintf_s(b, "%d", b_i);*/
			sprintf_s(sum_s, "%d", sum);
			/*if (strlen(a) > strlen(b)) max_len = strlen(a);
			else max_len = strlen(b);*/
			if (strlen(sum_s) > 9) //max_len)
			{
				char* s_copy = new char[10];
				strcut_p(sum_s, 1, s_copy);

				mas[max - count + 1] = s_copy;
				flag = 1;
				delete[] s_copy;
			}
			else
			{
				mas[max - count + 1] = sum_s;
				flag = 0;
			}
		}
		else
		{
			char sum_s[11];
			int a_i = *get(list, a_in);
			sum = a_i + flag;
			sprintf_s(sum_s, "%d", sum);
			if (strlen(sum_s) > 9)
			{
				char* s_copy = new char[10];
				strcut_p(sum_s, 1, s_copy);

				mas[max - count + 1] = s_copy;
				flag = 1;
				delete[] s_copy;
			}
			else
			{
				mas[max - count + 1] = sum_s;
				flag = 0;
			}
		}

		if (count == max && flag == 1)
		{
			mas[0] = "1";
		}
		else
		{
			mas[0] = "";
		}
		count++;
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