#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int month, day;
	cin >> month >> day;
	if (month < 1 || month > 12)
	{
		cout << "Не верно указан месяц"; return 0;
	}
	else
	{
		if (day < 1 || day > 31)
		{
			cout << "Не верно указан день"; return 0;
		}
		else
		{
			if (month == 2 && day > 28)
			{
				cout << "Не верно указан день"; return 0;
			}
			else
			{
				if (month == 4 && day > 30)
				{
					cout << "Не верно указан день"; return 0;
				}
				else
				{
					if (month == 6 && day > 30)
					{
						cout << "Не верно указан день"; return 0;
					}
					else
					{
						if (month == 9 && day > 30)
						{
							cout << "Не верно указан день"; return 0;
						}
						else
						{
							if (month == 11 && day > 30)
							{
								cout << "Не верно указан день"; return 0;
							}
						}
					}
				}
			}
		}
	}
	switch (month)
	{
	case 1:	cout << 365 - day + 1; break;
	case 2:	cout << 365 - 31 - day + 1;	break;
	case 3:	cout << 365 - 31 - 28 - day + 1; break;
	case 4:	cout << 365 - 31 - 28 - 31 - day + 1; break;
	case 5:	cout << 365 - 31 - 28 - 31 - 30 - day + 1; break;
	case 6:	cout << 365 - 31 - 28 - 31 - 30 - 31 - day + 1;	break;
	case 7:	cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - day + 1; break;
	case 8:	cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - day + 1; break;
	case 9:	cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - day + 1; break;
	case 10: cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - day + 1; break;
	case 11: cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - day + 1; break;
	case 12: cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - 30 - day + 1; break;
	}
	return 0;
}