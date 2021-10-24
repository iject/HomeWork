#include <iostream>
#include <cstdlib>
#include <ctime>
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

    const int n = 20;
    int array[n];

    int i_rand;

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int tmp;
        i_rand = rand() % n;

        tmp = array[i];
        array[i] = array[i_rand];
        array[i_rand] = tmp;
    }

    print_array(array, n);
}