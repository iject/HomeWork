#include "Header.h"

void enqueue(queue& queue, node* tree_node) {
	// Создаем новый элемент для размещения в очереди
	elem* newel = new elem;
	newel->node = tree_node;
	if (!queue.tail) {
		// Если очереди еще не было, новый элемент становится едиственным в ней
		queue.head = queue.tail = newel;
	}
	else {
		// Если очередь уже была, новый элемент помещается в конец:
		queue.tail->next = newel;
		queue.tail = newel;
	}
	queue.size++;
}
bool dequeue(queue& queue, node*& tree_node) {
	if (!queue.head) return false; // Очереди нет. Вернуть значение невозможно
	// Сохраняем возвращаемое значение
	tree_node = queue.head->node;
	// Сохраняем указатель на начало очереди
	elem* rem = queue.head;
	// Изменяем адрес головного элемента
	queue.head = queue.head->next;
	// Удаляем элемент с головы очереди
	delete rem;
	// Если элементов в очереди не осталось, обнуляем и указатель на ее конец.
	if (!queue.head) queue.tail = nullptr;
	queue.size--;
	return true;
}
void clear(queue& queue)
{
	// Проходим по всем элементам очереди, пока она не опустеет
	while (queue.head)
	{
		// Сохраняем ссылку на удаляемый элемент
		elem* rem = queue.head;
		// Переносим указатель вперед
		queue.head = queue.head->next;
		// Удаляем элемент по сохраненному указателю
		delete rem;
	}
	// Обнуляем размер очереди
	queue.size = 0;
	// Обновляем указатель на последний элемент
	queue.tail = nullptr;
}

/// Добавление элемента в дерево. Вспомогательная (внутренняя) функция.
bool _add_to_tree(node*& root, float value, string name);
bool _add_to_treeN(node*& root, float value, string name);
/// Удаление элемента из дерева. Вспомогательная (внутренняя) функция.
int _find_in_tree(const node* root, int value);
/// Безопасное получение высоты поддерева для заданного узла 
/// Перечисление возможных видов обхода дерева вглубь. Вспомогательный элемент.
enum _traverse_type { infix, prefix, postfix };
/// Функция обхода дерева вглубь. Вспомогательная (внутренняя) функция
void _traverse(queue& q, node* root, _traverse_type type);
/// Функция обхода дерева вширь
void _wide_traverse(queue& q, node*& root, bool include_empty);
/// Безопасное получение высоты поддерева для заданного узла и
/// сохранение (обновление) информации в узле
int _get_height(node* n);
/// Функция балансировки дерева или его части
void _balance(node*& n);
/// Функция выполнения малого левого поворота
void _small_left_rotate(node*& n);
/// Функция выполнения малого правого поворота
void _small_right_rotate(node*& n);
/// Функция выполнения большого левого поворота
void _big_left_rotate(node*& n);
/// Функция выполнения болоьшого правого поворота
void _big_right_rotate(node*& n);
void add_to_tree(tree& t, float value, string name, bool type)
{
	if (!type) {
		if (_add_to_tree(t.root, value, name)) t.elem_count++;
	}
	else
	{
		if (_add_to_treeN(t.root, value, name)) t.elem_count++;
	}
}
bool _add_to_tree(node*& root, float value, string name)
{
	// Проверяем, существует ли дерево
	if (root)
	{
		// Дерево уже существует. Определяем, куда разместить новый элемент
		// В зависимости от значения нового элемента относительного текущего…
		if (value == root->value)
		{
			// Если значение в новом элементе совпадает со значением в текущем элементе дерева
			// Вместо добавления элемента, увеличиваем количество таких элементов
			root->count++;
			root->name += " ; " + name;
			return false;
		}
		auto& branch =
			value < root->value ? root->left : root->right;
		// …рекурсивно размещаем элемент в левом или правом поддереве
		bool r = _add_to_tree(branch, value, name);
		// Выполнение балансировки дерева после добавления нового узла
		// Пересчет высоты узлов внесен в функцию балансировки
		if (r) _balance(root);
		return r;
	}
	// Если дерева нет, то новый элемент становится корневым
	// Создаем новый узел для размещения в дереве
	node* newnode = new node;
	newnode->value = value;
	newnode->name = name;
	// И помещаем в качестве текущего (корневого) узла
	root = newnode;
	return true;
}
bool _add_to_treeN(node*& root, float value, string name)
{
	// Проверяем, существует ли дерево
	if (root)
	{
		// Дерево уже существует. Определяем, куда разместить новый элемент
		// В зависимости от значения нового элемента относительного текущего…
		bool flag = false;
		int i = 0;
		while (name[i] == root->name[i]) {
			i++;
			if (i == min(name.size(), root->name.size())) {
				flag = true;
				break;
			}
		}
		if (flag) {
			if (name.size() > root->name.size())
			{
				auto& branch = root->right;
				bool r = _add_to_treeN(branch, value, name);
				if (r) _balance(root);
				return r;
			}
			else {
				auto& branch = root->left;
				bool r = _add_to_treeN(branch, value, name);
				if (r) _balance(root);
				return r;
			}
		}
		else {
			auto& branch = ((int)name[i] > (int)root->name[i]) ? root->left : root->right;
			bool r = _add_to_treeN(branch, value, name);
			if (r) _balance(root);
			return r;
		}
		// …рекурсивно размещаем элемент в левом или правом поддереве
		// Выполнение балансировки дерева после добавления нового узла
		// Пересчет высоты узлов внесен в функцию балансировки
	}
	// Если дерева нет, то новый элемент становится корневым
	// Создаем новый узел для размещения в дереве
	node* newnode = new node;
	newnode->value = value;
	newnode->name = name;
	// И помещаем в качестве текущего (корневого) узла
	root = newnode;
	return true;
}
void find_in_tree(const node* root, string letter, bool& f)
{
	// Если корень пуст, значит искомое значение не найдено, количество = 0
	if (!root) return;
	// Если значение имеется в корневом элементе, возвращаем количество
	if (root->name[0] == letter[0]) { f = true; cout << root->name << " ; " << endl; }
	// Иначе продолжаем рекурсивный поиск в поддеревьях
	if (letter[0] > root->name[0])
		find_in_tree(root->left, letter, f);
	find_in_tree(root->right, letter, f);
}
int _get_height(node* n)
{
	// Если узел пуст, сразу прерываем вычисления и возвращаем высоту = 0.
	if (!n) return 0;
	// Определяем сохраненные в структуру высоты левого и правого поддеревьев (если они существуют)
	auto lh = n->left ? n->left->height : 0;
	auto rh = n->right ? n->right->height : 0;
	// Высоту текущего узла рассчитываем как наибольшую из высот поддеревьев + 1
	return n->height = 1 + (lh > rh ? lh : rh);
}
void _traverse(queue& q, node* root, _traverse_type type) {
	// Реализация обхода дерева вглубь
	if (root)
	{
		switch (type)
		{
		case infix: // Обход вида LNR
		// Рекурсивный вывод значений левого поддерева (L)
			if (root->left) _traverse(q, root->left, type);
			// Вывод значений узла (N)
			enqueue(q, root);
			// Рекурсивный вывод значений правого поддерева (R)
			if (root->right) _traverse(q, root->right, type);
			break;
		case prefix: // Обход вида NLR
		// Вывод значения узла (N)
			enqueue(q, root);
			// Рекурсивный вывод значений левого поддерева (L)
			if (root->left) _traverse(q, root->left, type);
			// Рекурсивный вывод значений правого поддерева (R)
			if (root->right) _traverse(q, root->right, type);
			break;
		case postfix: // Обход вида LRN
		// Рекурсивный вывод значений левого поддерева (L)
			if (root->left) _traverse(q, root->left, type);
			// Рекурсивный вывод значений правого поддерева (R)
			if (root->right) _traverse(q, root->right, type);
			// Вывод значения узла (N)
			enqueue(q, root);
		}
	}
}
queue prefix_traverse(tree t)
{
	queue q;
	_traverse(q, t.root, prefix);
	return q;
}
queue infix_traverse(tree t)
{
	queue q;
	_traverse(q, t.root, infix);
	return q;
}
queue postfix_traverse(tree t)
{
	queue q;
	_traverse(q, t.root, postfix);
	return q;
}
queue wide_traverse(tree t, bool include_empty)
{
	queue q;
	_wide_traverse(q, t.root, include_empty);
	return q;
}
void _wide_traverse(queue& queue, node*& r, bool include_empty)
{
	// Проверка того, что дерево существует
	if (!r) return;
	// Корень дерева добавляется в очередь
	enqueue(queue, r);
	// Получение указателя на начало очереди
	auto q = queue.head;
	// Вычисление количества максимального числа узлов для дерева данной высоты
	// (без учета последнего уровня)
	const auto cnt = 1 << (r->height - 1);
	// Производится проход по очереди
	for (int i = 1; i < cnt && q; i++)
	{
		// Получаем указатели на левый и правый подузлы для текущего
		auto ln = q->node ? q->node->left : nullptr;
		auto rn = q->node ? q->node->right : nullptr;
		// Добавляем узлы в очередь если они не пустые, либо
		// параметр include_empty позволяет сохранять там пустые значения.
		// (Последнее необходимо для организации вывода на экран структуры дерева)
		if (ln || include_empty) enqueue(queue, ln);
		if (rn || include_empty) enqueue(queue, rn);
		q = q->next;
	}
}
void _balance(node*& n)
{
	// Проверяем, что переданный узел существует
	if (!n) return;
	// Определяем высоты левого и правого поддеревьев
	auto lh = _get_height(n->left);
	auto rh = _get_height(n->right);
	// Определяем разность высот двух поддеревьев
	auto dh = lh - rh;
	// Находим абсолютную величину разности
	dh = dh >= 0 ? dh : -dh;
	// Если разность высот 2 или более, требуется балансировка
	if (dh >= 2)
	{
		// Если правая ветвь длиннее, делаем левый поворот
		if (rh > lh)
		{
			// Определим высоты поддеревьев в правом поддереве
			auto rlh = _get_height(n->right->left);
			auto rrh = _get_height(n->right->right);
			// Если правое под-поддерево больше, делаем малый поворот
			if (rrh > rlh) _small_left_rotate(n);
			// иначе - большой
			else _big_left_rotate(n);
		}
		// Будем делать правый поворот, если левая ветвь больше
		else
		{
			// Определим высоты поддеревьев в левом поддереве
			auto llh = _get_height(n->left->left);
			auto lrh = _get_height(n->left->right);
			// Если левое под-поддерево больше, делаем малый поворот
			if (llh > lrh) _small_right_rotate(n);
			// иначе - большой
			else _big_right_rotate(n);
		}
	}
	else
	{
		// Разбалансировки нет. Просто уточняем высоту текущего узла
		_get_height(n);
	}
}
void _small_left_rotate(node*& n)
{
	// Узел правого поддерева будет новым корнем
	node* new_root = n->right;
	// Указатель на правое поддерево смещаем на узел, который стоит слева от нового корня
	n->right = new_root->left;
	// Указатель на левое поддерево для нового корня устанавливаем на старый корень
	new_root->left = n;
	// Выполняем пересчет высоты для старого корня
	_get_height(n);
	// Выполняем фактический перенос корня
	n = new_root;
	// Выполняем пересчет высоты для нового корня
	_get_height(n);
}
void _small_right_rotate(node*& n)
{
	// Данная функция является полностью зеркальной относительно предыдущей
	// Узел левого поддерева будет новым корнем
	node* new_root = n->left;
	// Указатель на левое поддерево смещаем на узел, который стоит справа от нового корня
	n->left = new_root->right;
	// Указатель на правое поддерево для нового корня устанавливаем на старый корень
	new_root->right = n;
	// Выполняем пересчет высоты для старого корня
	_get_height(n);
	// Выполняем фактический перенос корня
	n = new_root;
	// Выполняем пересчет высоты для нового корня
	_get_height(n);
}
void _big_left_rotate(node*& n)
{
	_small_right_rotate(n->right);
	_small_left_rotate(n);
}
void _big_right_rotate(node*& n)
{
	// Данная функция является полностью зеркальной относительно предыдущей
	_small_left_rotate(n->left);
	_small_right_rotate(n);
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

/**
 * Получение информации о длине сообщения от пользователя, переданного
 * методом POST
 */
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

/**
 * Получение данных из формы в необработанном виде
 */
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

/**
 * Получение значения конкретного параметра, полученного от пользователя
 */
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

/**
 * Раскодирование переданных данных
 */
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