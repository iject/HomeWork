#include<iostream>
#include<cmath>
using namespace std;

int f(int n)
{
	static int s = 0, sum = 0;
	if (n > 0)
	{
		sum += n % 10 * pow(2, s);
		s += 1;
		f(n / 10);
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	cout << f(n);

	return 0;
}