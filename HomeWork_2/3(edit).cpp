#include <iostream>
using namespace std;

int sum(int n)
{
    int s = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            s += i;
        }
    }
    return s;
}

int main()
{
    int s, last = 0;
    for (int i = 1; i < 10000; i++)
    {
        s = sum(i);
        for (int j = 1; j < 10000; j++)
        {
            if (s == j && sum(j) == i && i != last)
            {
                last = j;
                cout << i << " " << j << endl;
                i += 1;
            }
        }
    }
}