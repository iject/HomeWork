#include <iostream>
using namespace std;

void print_array(int array[], const int size)
{
    cout << "Массив размера " << size << ": " << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << "array[" << i << "] = " << array[i] << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int a, d;
    const int n = 20;

    int array[n];
    cout << "Введите первый элемент: " << "\n" << ">> ";
    cin >> a;
    cout << "Введите разность элементов: " << "\n" << ">> ";
    cin >> d;

    for (int i = 0; i < n; i++)
    {
        array[i] = a;
        a += d;
    }
    print_array(array, n);
}
