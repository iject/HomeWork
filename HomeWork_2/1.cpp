#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int a, b;
	srand(time(0));
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;

	cout << "Первый кубик -- " << a << endl << "Второй кубик -- " << b;
}