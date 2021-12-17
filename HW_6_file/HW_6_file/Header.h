#pragma once
void create_mas(int** mas, int n, int m);
void rand_mas(int* mas[], int n, int m);
void print_mas(int* mas[], int n, int m);
void min_elem(int** mas, int n, int m);
int min_el_i(int** mas, int n, int m);
int min_el_j(int** mas, int n, int m);
int min_polel_i(int** mas, int n, int m);
int min_polel_j(int** mas, int n, int m);
void delete_min(int** mas, int n, int m);
int mult_el_i_j(int** mas, int** mas_2, int m, int i_m, int j_m);
void mult_mas(int** mas, int** mas_2, int** mas_mult, int n, int m_2, int m);
void swp_mas(int** mas, int n, int m);
void swp_tabl(int** mas, int n);
int min_str(int** mas, int n, int i);
int max_str(int** mas, int n, int i);
void swp_min_max(int** mas, int n, int m);
void delete_mas(int** mas, int n, int m);