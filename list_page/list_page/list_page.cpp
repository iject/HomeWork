#include <iostream>
#include <string>
#include <fstream>
#include "list_page.h"
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
    cout << "<form method='get' action='list_page.cgi'>";
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

        elem* list = nullptr;

        if (not_empty("buf.txt")) r_list("buf.txt", list);


        string str = string(value);
        if (str.find(" ") != string::npos)
        {
            char* s_copy = new char[strlen(value) + 1];
            strcpy_s(s_copy, strlen(value) + 1, value);
            char* context;
            char* temp = s_copy;
            char* part = strtok_s(temp, " ", &context);

            int a, b;
            sscanf_s(part, "%d", &a);
            sscanf_s(context, "%d", &b);
            insert(list, a, b);
        }
        else
        {
            int a;
            sscanf_s(value, "%d", &a);
            add(list, a);
        }


        w_list("buf.txt", list);


        cout << "<div><p><b>List: </b></p></div>";
        show_list(list);
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
    cout << "Список";
}