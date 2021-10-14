#include <iostream>
using namespace std;

int sum(int n, int k)
{
    int s = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            s += i;
        }
        if (s > k) return 0;
    }
    return s;
}

int main()
{
    for (int i = 1; i < 10000; i++)
    {
        for (int j = 1; j < 10000; j++)
        {
            if (sum(i, j) == j)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}