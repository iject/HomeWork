#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	// #1
	cout << "Task #1 \"delete\"\nВведите кол-во строк и столбцов:\n";
	cin >> n >> m;
	int** mas1 = new int* [n];
	create_mas(mas1, n, m);

	rand_mas(mas1, n, m);
	print_mas(mas1, n, m);
	cout << endl;

	min_elem(mas1, n, m);
	cout << endl;

	delete_min(mas1, n, m);
	print_mas(mas1, n, m);

	delete_mas(mas1, n, m);

	// #2
	int n_2, m_2;
	cout << "Task #2 \"mult\"\n";
	cout << "Введите кол-во строк 1 матрицы: ";
	cin >> n;
	cout << "Введите кол-во столбцов 1 матрицы: ";
	cin >> m;
	cout << "Введите кол-во строк 2 матрицы: ";
	cin >> n_2;
	cout << "Введите кол-во столбцов 2 матрицы: ";
	cin >> m_2;

	int** mas2 = new int* [n];
	create_mas(mas2, n, m);
	int** mas2_2 = new int* [n_2];
	create_mas(mas2_2, n_2, m_2);

	rand_mas(mas2, n, m);
	print_mas(mas2, n, m);
	cout << endl;
	rand_mas(mas2_2, n_2, m_2);
	print_mas(mas2_2, n_2, m_2);
	cout << endl;

	int** mas_mult = new int* [n];
	create_mas(mas_mult, n, m_2);
	if (m == n_2)
	{
		mult_mas(mas2, mas2_2, mas_mult, n, m_2, m);
	}
	else
	{
		cout << "Кол-во столбцов 1 матрицы не равно кол-ву строк 2 матрицы\n";
	}
	print_mas(mas_mult, n, m_2);

	delete_mas(mas2, n, m);
	delete_mas(mas2_2, n, m);
	delete_mas(mas_mult, n, m);


	// #3
	cout << "Task #3 \"swp_diag\"\n";
	cout << "Введите размер матрицы: ";
	cin >> n;
	int** mas3 = new int* [n];
	create_mas(mas3, n, n);

	rand_mas(mas3, n, n);
	print_mas(mas3, n, n);
	cout << endl;

	swp_mas(mas3, n, n);
	print_mas(mas3, n, n);

	delete_mas(mas3, n, m);

	// #4
	cout << "task #4 \"swp_tabl\"\n";
	cout << "введите размер таблицы: ";
	cin >> n;
	int** mas4 = new int* [n];
	create_mas(mas4, n, n);

	rand_mas(mas4, n, n);
	print_mas(mas4, n, n);
	cout << endl;

	cout << "минимальный положительный эл - т: " << mas4[min_polel_i(mas4, n, n)][min_polel_j(mas4, n, n)]
		<< "(" << min_polel_i(mas4, n, n) << "," << min_polel_j(mas4, n, n) << ")\n\n";

	swp_tabl(mas4, n);
	print_mas(mas4, n, n);

	delete_mas(mas4, n, m);

	// #5
	cout << "Task #5 \"swp_tabl\"\n";
	cout << "Введите кол-во строк таблицы: ";
	cin >> n;
	cout << "Введите кол-во столбцов таблицы: ";
	cin >> m;
	int** mas5 = new int* [n];
	create_mas(mas5, n, m);

	rand_mas(mas5, n, m);
	print_mas(mas5, n, m);
	cout << endl;

	swp_min_max(mas5, n, m);
	print_mas(mas5, n, m);

	delete_mas(mas5, n, m);
}