#pragma once

struct man
{
	char name[50];
	char sex[50];
	int age;
	char job[50];
	int income;
	char goal[50];
};

struct elem
{
	man m;
	elem* next = nullptr;
};

struct queue
{
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t size = 0;
};

inline man create_elem(const char* name, const char* sex, int age, const char* job, int income, const char* goal);

//помещение нового элемента в очередь
void enqueue(queue& queue, const char* name, const char* sex, int age, const char* job, int income, const char* goal);

//извлечение элемента из очереди 
bool dequeue(queue& queue, man& man);

//удаление очереди
void clear(queue& queue);

void Show(queue& queue);

void load_data(const char* filename, queue& people_credit, queue& people_contribution);