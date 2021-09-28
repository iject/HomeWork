#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int count;
	cin >> count;
	if (count >= 100 && count <= 999) {
		cout << "Число трёхзначное";
	}
	else {
		cout << "Число не трёхзначное";
	}
	return 0;
}