#include <iostream>
using namespace std;

void rand_array(int* array, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 90 + 1;
    }
}

void print_array(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void move_left(int* array, int begin, int end)
{
    int tmp = array[begin];
    for (int i = begin; i < end; i++)
    {
        array[i] = array[i + 1];
    }
    array[end] = tmp;
}

void move_right(int* array, int begin, int end)
{
    int tmp = array[end];
    for (int i = end; i > begin; i--)
    {
        array[i] = array[i - 1];
    }
    array[begin] = tmp;
}

//void qsort_Hoar()
//{
//    if (begin == end) return;
//    qsort
//}

void qsort(int* array, int begin, int end)
{
    int mid = begin + (end - begin) / 2;
    for (int i = 0; i <= end; i++)
    {
        if (array[i] > array[mid] && i < mid)
        {
            move_left(array, i, mid);
            mid--;
            i--;
            cout << "move_left: ";
            print_array(array, end + 1);
        }

        if (array[i] < array[mid] && i > mid)
        {
            move_right(array, mid, i);
            mid++;
            cout << "move_right: ";
            print_array(array, end + 1);
        }
    }
    if (begin < mid-1)
    {
        qsort(array, begin, mid - 1);
    }
    if (mid+1 < end)
    {
        qsort(array, mid + 1, end);
    }
    return;
}



int main()
{
    int n = 10;
    //cout << "input n\n";
    //cin >> n;
    int* array = new int[n];

    rand_array(array, n);

    print_array(array, n);

    qsort(array, 0, n - 1);

    print_array(array, n);

    delete[] array;
}