#include "Header.h"


void add(list2& list, int data)
{
	// Создание нового элемента списка
	elem* newel = new elem;
	newel->x = data;
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
		newel->prev = list.last;
		list.last->next = newel;
		list.last = newel;
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

void show_list(const list2& list, bool reversed)
{
	// Устанавливаем указатель на начало или конец списка в зависимости от порядка
	// вывода его элементов, определяемого параметром reversed
	elem* curr = reversed ? list.last : list.first;
	if (!curr) cout << "Список пуст" << endl;// Список пуст
	// Пробегаем по всем элементам списка и выводим значения
	else while (curr)
	{
		elem* cmp = reversed ? list.first : list.last;
		cout << curr->x << ((curr == cmp) ? "\n" : " ");
		curr = reversed ? curr->prev : curr->next;
	}
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