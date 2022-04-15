#include<iostream>
#include<fstream>
#include<cstring>
#include"Header.h"
using namespace std;

inline man create_elem(const char* name, const char* sex,
	int age, const char* job, int income, const char* goal) {
	man m;
	strcpy_s(m.name,name);
	strcpy_s(m.sex,sex);
	m.age = age;
	strcpy_s(m.job,job);
	m.income = income;
	strcpy_s(m.goal,goal);

	return m;
}

//помещение нового элемента в очередь
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

//извлечение элемента из очереди 
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

//удаление очереди
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
		cout << m.name << " " << m.sex << " " << m.age <<
			" " << m.job << " " << m.income << " " << m.goal<< endl;
	}
}

void load_data(const char* filename, queue& people_credit, queue& people_contribution)
{
	ifstream f(filename);
	if (f.is_open())
	{
		//До конца файла
		while (!f.eof())
		{
			char* str = new char[60];
			//Считываем очередную строку
			f.getline(str, 60);
			char name[50];
			char sex[50];
			int age;
			char job[50];
			int income;
			char goal[50];
			//Получаем имя и возраст человека в отдельных переменных
			sscanf_s(str, "%s %s %d %s %d %s", 
				name, 50, sex, 50, &age, job, 50, &income, goal, 50);
			if (string(goal) == "Кредит") enqueue(people_credit, name, sex, age, job, income, goal);
			else enqueue(people_contribution, name, sex, age, job, income, goal);
		}
		f.close();
	}
}