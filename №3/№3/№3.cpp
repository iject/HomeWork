#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cin >> n;

	// миллионы
	switch (n / 1000000)
	{
	case 10: cout << "десять миллионов "; break;
	case 11: cout << "одиннадцать миллионов "; break;
	case 12: cout << "двенадцать миллионов "; break;
	case 13: cout << "тринадцать миллионов "; break;
	case 14: cout << "четырнадцать миллионов "; break;
	case 15: cout << "пятнадцать миллионов "; break;
	case 16: cout << "шестнадцать миллионов "; break;
	case 17: cout << "семнадцать миллионов "; break;
	case 18: cout << "восемнадцать миллионов "; break;
	case 19: cout << "девятнадцать миллионов "; break;
	}
	switch (n / 10000000)
	{
	case 2: cout << "двадцать "; break;
	case 3: cout << "тридцать "; break;
	case 4: cout << "сорок "; break;
	case 5: cout << "пятьдесят "; break;
	case 6: cout << "шестьдесят "; break;
	case 7: cout << "семьдесят "; break;
	case 8: cout << "восемьдесят "; break;
	case 9: cout << "девяносто "; break;
	}
	if (n / 10000000 != 1)
	{
		switch (n / 1000000 % 10)
		{
		case 1: cout << "один миллион "; break;
		case 2: cout << "два миллиона "; break;
		case 3: cout << "три миллиона "; break;
		case 4: cout << "четыре миллиона "; break;
		case 5: cout << "пять миллионов "; break;
		case 6: cout << "шесть миллионов "; break;
		case 7: cout << "семь миллионов "; break;
		case 8: cout << "восемь миллионов "; break;
		case 9: cout << "девять миллионов "; break;
		case 0: if (n / 10000000 > 1) cout << "миллионов "; break;
		}
	}

	// тысячи
	switch (n / 100000 % 10)
	{
	case 1: cout << "сто "; break;
	case 2: cout << "двести "; break;
	case 3: cout << "триста "; break;
	case 4: cout << "четыреста "; break;
	case 5: cout << "пятьсот "; break;
	case 6: cout << "шестьсот "; break;
	case 7: cout << "семьсот "; break;
	case 8: cout << "восемьсот "; break;
	case 9: cout << "девятьсот "; break;
	}
	switch (n / 1000 % 100)
	{
	case 10: cout << "десять тысяч "; break;
	case 11: cout << "одиннадцать тысяч "; break;
	case 12: cout << "двенадцать тысяч "; break;
	case 13: cout << "тринадцать тысяч "; break;
	case 14: cout << "четырнадцать тысяч "; break;
	case 15: cout << "пятнадцать тысяч "; break;
	case 16: cout << "шестнадцать тысяч "; break;
	case 17: cout << "семнадцать тысяч "; break;
	case 18: cout << "восемнадцать тысяч "; break;
	case 19: cout << "девятнадцать тысяч "; break;
	}
	switch (n / 10000 % 10)
	{
	case 2: cout << "двадцать "; break;
	case 3: cout << "тридцать "; break;
	case 4: cout << "сорок "; break;
	case 5: cout << "пятьдесят "; break;
	case 6: cout << "шестьдесят "; break;
	case 7: cout << "семьдесят "; break;
	case 8: cout << "восемьдесят "; break;
	case 9: cout << "девяносто "; break;
	}
	if (n / 10000 % 10 != 1)
	{
		switch (n / 1000 % 10)
		{
		case 1: cout << "одна тысяча "; break;
		case 2: cout << "две тысячи "; break;
		case 3: cout << "три тысяча "; break;
		case 4: cout << "четыре тысяча "; break;
		case 5: cout << "пять тысяч "; break;
		case 6: cout << "шесть тысяч "; break;
		case 7: cout << "семь тысяч "; break;
		case 8: cout << "восемь тысяч "; break;
		case 9: cout << "девять тысяч "; break;
		case 0: if (n / 1000 % 10 > 1) cout << "тысяч "; break;
		}
	}

	// сотни
	switch (n / 100 % 10)
	{
	case 1: cout << "сто "; break;
	case 2: cout << "двести "; break;
	case 3: cout << "триста "; break;
	case 4: cout << "четыреста "; break;
	case 5: cout << "пятьсот "; break;
	case 6: cout << "шестьсот "; break;
	case 7: cout << "семьсот "; break;
	case 8: cout << "восемьсот "; break;
	case 9: cout << "девятьсот "; break;
	}

	// десятки
	switch (n % 100)
	{
	case 10: cout << "десять "; break;
	case 11: cout << "одиннадцать "; break;
	case 12: cout << "двенадцать "; break;
	case 13: cout << "тринадцать "; break;
	case 14: cout << "четырнадцать "; break;
	case 15: cout << "пятнадцать "; break;
	case 16: cout << "шестнадцать "; break;
	case 17: cout << "семнадцать "; break;
	case 18: cout << "восемнадцать "; break;
	case 19: cout << "девятнадцать "; break;
	}
	switch (n / 10 % 10)
	{
	case 2: cout << "двадцать "; break;
	case 3: cout << "тридцать "; break;
	case 4: cout << "сорок "; break;
	case 5: cout << "пятьдесят "; break;
	case 6: cout << "шестьдесят "; break;
	case 7: cout << "семьдесят "; break;
	case 8: cout << "восемьдесят "; break;
	case 9: cout << "девяносто "; break;
	}
	if (n / 10 % 10 != 1)
	{
		switch (n % 10)
		{
		case 1: cout << "один "; break;
		case 2: cout << "два "; break;
		case 3: cout << "три  "; break;
		case 4: cout << "четыре "; break;
		case 5: cout << "пять "; break;
		case 6: cout << "шесть "; break;
		case 7: cout << "семь "; break;
		case 8: cout << "восемь "; break;
		case 9: cout << "девять "; break;
		}
	}
	return 0;
}