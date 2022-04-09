#include<iostream>
#include<string>
#include"Header.h"
using namespace std;

int main()
{
	elem* stack = nullptr;
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		string sk_open = "([{<";
		string sk_close = ")]}>";
		if (sk_open.find(s[i]) != -1)
		{
			push(stack, s[i]);
		}
		if (sk_close.find(s[i]) != -1)
		{
			char speek = peek(stack);
			if (speek == 'e')
			{
				cout << "i = " << i << "\n";
				return 0;
			}

			if (speek == '(' && s[i] != ')')
			{
				cout << "i = " << i << "\n";
				return 0;
			}
			if (speek == '[' && s[i] != ']')
			{
				cout << "i = " << i << "\n";
				return 0;
			}
			if (speek == '{' && s[i] != '}')
			{
				cout << "i = " << i << "\n";
				return 0;
			}
			if (speek == '<' && s[i] != '>')
			{
				cout << "i = " << i << "\n";
				return 0;
			}
		}
	}

	ShowStack(stack);
}