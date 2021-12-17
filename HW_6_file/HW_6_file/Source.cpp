#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Header.h"

using namespace std;

void create_mas(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[m];
	}
}

void rand_mas(int* mas[], int n, int m)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 101 - 50;
		}
	}
}

void print_mas(int* mas[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << '\t';
		}
		cout << "\n";
	}
	cout << "\n";
}

void min_elem(int** mas, int n, int m)
{
	int min_i = 0, min_j = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] < mas[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	cout << "Минимальный эл-т: " << mas[min_i][min_j] << "(" << min_i << ", " << min_j << ")\n";
}

int min_el_i(int** mas, int n, int m)
{
	int min_i = 0, min_j = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] < mas[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	return min_i;
}

int min_el_j(int** mas, int n, int m)
{
	int min_i = 0, min_j = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] < mas[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	return min_j;
}

int min_polel_i(int** mas, int n, int m)
{
	int min_i, min_j;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] > 0)
			{
				min_i = i;
				min_j = j;
				j = n;
				i = n;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((mas[i][j] < mas[min_i][min_j]) && (mas[i][j] > 0))
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	return min_i;
}

int min_polel_j(int** mas, int n, int m)
{
	int min_i, min_j;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] > 0)
			{
				min_i = i;
				min_j = j;
				j = n;
				i = n;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((mas[i][j] < mas[min_i][min_j]) && (mas[i][j] > 0))
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	return min_j;
}

void delete_min(int** mas, int n, int m)
{
	int min_i = min_el_i(mas, n, m), min_j = min_el_j(mas, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = min_j; j < m - 1; j++)
		{
			mas[i][j] = mas[i][j + 1];
		}
		mas[i][m - 1] = 0;
	}

	for (int i = min_i; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			mas[i][j] = mas[i + 1][j];
		}
	}

	for (int j = 0; j < m; j++)
	{
		mas[n - 1][j] = 0;
	}
}

int mult_el_i_j(int** mas, int** mas_2, int m, int i_m, int j_m)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += mas[i_m][i] * mas_2[i][j_m];
	}

	return sum;
}

void mult_mas(int** mas, int** mas_2, int** mas_mult, int n, int m_2, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_2; j++)
		{
			mas_mult[i][j] = mult_el_i_j(mas, mas_2, m, i, j);
		}
	}
}


void swp_mas(int** mas, int n, int m)
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp = mas[i][j];
			mas[i][j] = mas[n - 1 - j][n - 1 - i];
			mas[n - 1 - j][n - 1 - i] = tmp;
		}
		m -= 1;
	}
}

void swp_tabl(int** mas, int n)
{
	int tmp, i_min, j_min, j = 0;
	i_min = min_polel_i(mas, n, n);
	j_min = min_polel_j(mas, n, n);

	for (int i = 0; i < n; i++)
	{
		if (mas[i_min][i] == mas[i_min][j_min] && (i + 1) < n)
		{
			i += 1;
		}

		if (mas[j][j_min] == mas[i_min][j_min] && (j + 1) < n)
		{
			j += 1;
		}
		tmp = mas[i_min][i];
		mas[i_min][i] = mas[j][j_min];
		mas[j][j_min] = tmp;
		j += 1;
	}
}

int min_str(int** mas, int n, int i)
{
	int min = 0;
	for (int k = 0; k < n; k++)
	{
		if (mas[i][k] < mas[i][min])
		{
			min = k;
		}
	}
	return min;
}

int max_str(int** mas, int n, int i)
{
	int max = 0;
	for (int k = 0; k < n; k++)
	{
		if (mas[i][k] > mas[i][max])
		{
			max = k;
		}
	}
	return max;
}

void swp_min_max(int** mas, int n, int m)
{
	for (int i = 1; i < n; i++)
	{
		mas[i][min_str(mas, m, i)] = mas[i - 1][max_str(mas, m, i - 1)];
	}
}

void delete_mas(int** mas, int n, int m)
{
	for (int i = 1; i < n; i++)
	{
		delete[] mas[i];
	}

	delete[] mas;
}