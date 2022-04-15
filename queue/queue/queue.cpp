#include<iostream>
#include<fstream>
#include<cstring>
#include"Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	queue people_credit;
	queue people_contribution;
	load_data("data.txt", people_credit, people_contribution);
	cout << "---credit---\n";
	Show(people_credit);
	cout << "\n---contribution---\n";
	Show(people_contribution);
}
