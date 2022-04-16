#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void show_menu();

void show_content();

void show_header();

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Content-type: text/html; charset=Windows-1251\n\n";

    ifstream f("_index");
    if (f.is_open())
    {
        auto sz = 65536;
        auto buf = new char[sz];
        while (!f.eof())
        {
            f.getline(buf, sz);
            if (!strcmp(buf, "<!--#CONTENT#-->"))
            {
                show_content();
            }
            else if (!strcmp(buf, "<!--#MENU#-->"))
            {
                show_menu();
            }
            else if (!strcmp(buf, "<!--#HEADER#-->"))
            {
                show_header();
            }
            cout << buf;
        }
        delete[] buf;
        f.close();
    }
    else
    {
        cout << "Не удалось открыть файл :(";
    }

}
    
void show_content()
{
    cout << "Выберете задание из меню";
}   

void show_menu()
{
    ifstream f("_menu");
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
    delete[] buf;
    f.close();
}

void show_header()
{
    cout << "Главная страница";
}