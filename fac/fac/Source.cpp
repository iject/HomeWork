#include "Header.h"


void add(list2& list, int data)
{
	// �������� ������ �������� ������
	elem* newel = new elem;
	newel->x = data;
	// ��� ������� �������� ����������� ����� ������
	list.count++;
	// �������� ������� ������
	if (!list.first)
	{
		// ���� ������ ��� �� ����, ����� ������� ����� ������
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
		return false; // ������ �������� ���.
	list.count--; // ���������� ��������� ����� ���������.
	if (pos == 0)
	{
		// ��������� ������ �������
		elem* rem = list.first;
		// �������� ��������� �� ������ ������
		list.first = list.first->next;
		if (list.first) list.first->prev = nullptr;
		delete rem;
		return true;
	}
	if (pos == list.count)
	{
		// ��������� ��������� �������
		elem* rem = list.last;
		// �������� ��������� �� ����� ������
		list.last = list.last->prev;
		list.last->next = nullptr;
		delete rem;
		return true;
	}
	// ��������� ������� �� �������� ������
// ���������� ����������� ������ ������
	bool frw = (pos <= list.count / 2);
	int p = 1;
	elem* curr;
	if (frw) {
		// ���� ��������� ������� �� ������ ��������, ��������� �� ������...
		curr = list.first->next;
	}
	else {
		// ...����� - � �����.
		pos = list.count - pos;
		curr = list.last->prev;
	}
	// ��������� �� ������ �� �������� ��������, ���� �� ����� ������
	while (p < pos) {
		// ������ ������ ��� ����� � ����������� �� ����������� �������� �� ������
		curr = frw ? curr->next : curr->prev;
		p++;
	}
	// ������������ ��������� � ����������� ��������
	curr->prev->next = curr->next;
	// ������������ ��������� � ���������� ��������
	curr->next->prev = curr->prev;
	// ������� ������� �������
	delete curr;
	return true;
}

const int* get(list2 list, int pos) {
	if (!list.first || pos < 0 || pos >= list.count)
		return nullptr; // ������ �������� ���
	if (!pos)return &list.first->x; // ���������� �������� ������� ��������
	if (pos == list.count - 1)
		return &list.last->x; // ���������� �������� ���������� ��������
		// ����� ���� ������� � ������ �������
	int p = 1;
	// ���������� ���������������� ����������� ������
	bool fwd = pos <= list.count / 2;
	elem* curr;
	// ������� ��������� �������
	if (fwd)
		curr = list.first->next;
	else {
		curr = list.last->prev;
		// ������������ ����� �������� �������� � ����������� �� ����������� ������
		pos = list.count - pos - 1;
	}
	while (curr && p < pos) {
		p++;
		// ��������� ������ ��� ����� � ����������� �� ����������� ������
		curr = fwd ? curr->next : curr->prev;
	}
	// ����� ��������� ��������� �� ������� ��������
	return &curr->x;
}

void show_list(const list2& list, bool reversed)
{
	// ������������� ��������� �� ������ ��� ����� ������ � ����������� �� �������
	// ������ ��� ���������, ������������� ���������� reversed
	elem* curr = reversed ? list.last : list.first;
	if (!curr) cout << "������ ����" << endl;// ������ ����
	// ��������� �� ���� ��������� ������ � ������� ��������
	else while (curr)
	{
		elem* cmp = reversed ? list.first : list.last;
		cout << curr->x << ((curr == cmp) ? "\n" : " ");
		curr = reversed ? curr->prev : curr->next;
	}
}

void clear(list2& list)
{
	// ������� ������� ����������� ������ ����������� �� ���������� �� �������
	// ��� ������ ������������.
	elem* rem;
	while (list.first)
	{
		rem = list.first;
		list.first = list.first->next;
		delete rem;
	}
	list.last = nullptr; // ������������ ��������� �� ��������� �������
	list.count = 0; // ������������ ���������� ��������� ������
}