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

    int s = 0;

    const int n = 20;
    int array[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 1001 + 1000;
        if (array[i] % 100 / 10 % 2 == 0) s += 1;
    }
    print_array(array, n);
    cout << "В массиве " << s <<  " элементов, у которых вторая с конца цифра – чётная";
}
