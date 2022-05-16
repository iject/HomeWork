#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
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
    cout << "<form method='get' action='list2_page.cgi'>";
    cout << "<p><b>Введите выражение: </b></p>";
    cout << "<p><textarea cols='30' rows='8' name='longtext'></textarea></p>";
    cout << "<p><input type='submit' value='Отправить'></p>";
    cout << "</form>";

#ifndef _DEBUG
    char* data = nullptr;
    get_form_data(data);
#else
    const char* data = "longtext=fill";
#endif
    if (data && strlen(data) > 0)
    {
        char* value = nullptr;
        get_param_value(value, "longtext", data);

        list2 list;

        char* s_copy = new char[strlen(value) + 1];
        strcpy_s(s_copy, strlen(value) + 1, value);
        char* context;
        char* temp = s_copy;
        char* part = strtok_s(temp, " ", &context);

        char a[30], b[30];
        sscanf_s(part, "%29s", a, (unsigned)_countof(a));
        sscanf_s(context, "%29s", b, (unsigned)_countof(b));

        int max;
        razb_group(list, a, b, max);
        string* mas = new string[max + 2];
        sum(list, max, mas);


        cout << "<div><p><b>Исходное выражение: </b></p></div>";
        cout << "<div><b>" << a << " " << b << " </b></div>";
        cout << "<div><p><b>List2: </b></p></div>";
        show_list(list, true);

        cout << "<div><p><b>Сумма: </b></p></div>";
        for (int i = 0; i < max + 2; i++)
        {
            cout << "<b>" << mas[i] << "</b>";
        }
        delete[] mas;
    }
    delete[] data;
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
    cout << "Список_2";
}