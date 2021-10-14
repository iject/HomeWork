#include<iostream>
using namespace std;

int Fib(int n)
{
	if (n == 1 || n == 2) return 1;
	if (n > 2)
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	cout << "Число Фиббоначи под номером " << n << " = " << Fib(n) << "\n";
	
}