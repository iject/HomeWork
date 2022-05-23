#include <iostream>
#include "Header.h"

using namespace std;

//Вспомогательные функции для создания и отображения дерева
/// Перечисление возможных видов обхода дерева.
enum traverse_type { prefix, infix, postfix, wide };
/// Функция отображает на экране элементы из очереди, составленной из элементов дерева
void find_let(tree tree, char* letter, bool& r, traverse_type tt = wide, bool show_empty = true)
{
	// Формирование очереди для выполнения обхода определенного вида
	queue tq;
	switch (tt)
	{
	case prefix:tq = prefix_traverse(tree); break;
	case infix:tq = infix_traverse(tree); break;
	case postfix:tq = postfix_traverse(tree); break;
	case wide:tq = wide_traverse(tree, show_empty); break;
	}
	// Получение элемента с головы очереди для начала обхода
	auto got = tq.head;
	// Пока в очереди есть элементы
	while (got)
	{
		auto n = got->node;
		// Если элемент не пуст, выводится его значение
		// и в скобках количество таких значений в исходном наборе
		if (n && n->name[0] == letter[0]) { r = true; cout << n->name << " " << n->value << "<br>"; }
		// Если элемент пуст, вместо его значения выводится прочерк
			// Переходим к следующему по очереди элементу
		got = got->next;
		// Выводим символ-разделитель: пробел, если в очереди еще есть элементы
		// или символ перехода на новую строку, если элемент был последним.
	}
	// Удаление вспомогательной очереди
	clear(tq);
}
void show_treeM(node* root, int hght)
{
	if (!root) return;
	show_treeM(root->left, hght + 1);
	cout << "<tr class='table'><td>" << hght;
	for (int i = 0; i < hght; i++)
		cout << ".";
	cout << "</td>  ";
	cout << "<td >" << root->name << "</td> " << "<td>" << root->value << "(" << root->count << ") </td>" << "</tr>";
	show_treeM(root->right, hght + 1);
}
void show_content(tree& tree);
void input_data(const char* filename, tree& tree, bool type)
{
	ifstream f(filename);
	if (f.is_open())
	{
		while (!f.eof())
		{
			char* student = new char[200];
			f.getline(student, 200);
			char* name = new char[50];
			float point;
			sscanf_s(student, "%s %f", name, 50, &point);
			add_to_tree(tree, point, name, type);
		}
		f.close();
	}
	else
		cout << "Файл не открылся";
}

void show_menu();

void show_header();

void main()
{
	tree tree;
	node* node;
	setlocale(LC_ALL, "Rus");
	cout << "Content-type: text/html; charset=Windows-1251\n\n";

	ifstream fo("_index");
	if (fo.is_open())
	{
		auto sz = 65536;
		auto buf = new char[sz];
		while (!fo.eof())
		{
			fo.getline(buf, sz);

			if (!strcmp(buf, "<!--#CONTENT#-->"))
			{
				show_content(tree);
			}
			else if (!strcmp(buf, "<!--#MENU#-->"))
			{
				show_menu();
			}
			else if (!strcmp(buf, "<!--#HEADER#-->"))
			{
				show_header();
			}

			/*if (strcmp(buf, "<!--#TITLE#-->") == 0)
			{
				cout << "<h1 class='title'>Бинарное дерево</h1>";
			}
			if (strcmp(buf, "<!--#CONTENT#-->") == 0)
			{
				show_content(tree);
			}*/
			cout << buf;
		}
		delete[] buf;
		fo.close();
	}
	else
	{
		cout << "Не удалось открыть файл :(";
	}
}

void show_content(tree& tree) {
	setlocale(LC_ALL, "rus");
	cout << "<form method='get' action='tree_page.cgi'>";
	cout << "<input type='text' class='enter' name='tree' placeholder='Введите: 0 (построить дерево по среднему баллу) или 1 (по фамилиям студентов) или же букву для поиска по фамилиям'>";
	cout << "<input type='submit' value='Отправить' class='button'></input>";
	cout << "</form>";
	cout << "<h2 class = 'result'>Общий список студентов: </h2>";
	cout << "<div class = 'output'>";

	char* data = nullptr;
	get_form_data(data);

	if ((data && strlen(data)) > 0)
	{
		char* value = nullptr;
		get_param_value(value, "tree", data);
	
		if ((value[0] - 48) == 0)
		{
			input_data("students.txt", tree, 0);
			cout << "<p style = 'margin: 10px'> Дерево по среднему баллу: </p>";
			cout << "<table cellspacing = '4' border='4px' border='4px' > <tr> <td> Уровень дерева. </td> <td> Имя студента. </td> <td> Средний балл. </td> <tr>";
			show_treeM(tree.root, 0);
			cout << "</table> </div>";
		}
		else if ((value[0] - 48) == 1)
		{
			input_data("students.txt", tree, 1);
			cout << "<p style = 'margin: 10px'> Дерево по фамилиям: </p>";
			cout << "<table cellspacing = '4' border='4px' border='4px' > <tr> <td> Уровень дерева. </td> <td> Имя студента. </td> <td> Средний балл. </td> <tr>";
			show_treeM(tree.root, 0);
			cout << "</table> </div>";
		}
		else if (strlen(value) == 1)
		{
			bool r = 0;
			input_data("students.txt", tree, 1);
			find_let(tree, value, r);
			if (!r) cout << "Ничего не нашлось";
		}
		else
		{
			cout << "Ошибка ввода";
		}
	}
	else {
		ifstream fr("students.txt");
		if (fr.is_open())
		{
			string std;
			while (!fr.eof()) {
				getline(fr, std);
				cout << std << "<br>";
			}
			fr.close();
		}
	}
}

void show_menu()
{
	ifstream f("_menu");
	if (f.is_open())
	{
		auto sz = 1024;
		auto buf = new char[sz];
		while (!f.eof())
		{
			f.getline(buf, sz);
			char* name;
			char* addrr = strtok_s(buf, " ", &name);
			cout << "<div class = 'menu-item'>"
				"<a href = '" << addrr << "'>" <<
				name << "</a>"
				"</div>";
		}
	}
	f.close();
}

void show_header()
{
	cout << "Дерево";
}