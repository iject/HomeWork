#include <iostream>
#include <string>
#include <fstream>
#include "CGI.h"
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
    cout << "<form method='get' action='second.cgi'>";
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
        //cout << "<div>" << data << "</div>";
        char* value = nullptr;
        get_param_value(value, "longtext", data);
        cout << "<div><b> Введённое выражение: " << value << "</b></div>";

        elem* stack = nullptr;
        string s = string(value);

        string sk_open = "([{<";
        string sk_close = ")]}>";
        for (int i = 0; i < s.size(); i++)
        {
            if (sk_open.find(s[i]) != -1)
            {
                push(stack, s[i]);
            }
            if (sk_close.find(s[i]) != -1)
            {
                char speek = peek(stack);
                if (speek == 'e')
                {
                    cout << "<div><b>Ошибка на " << i+1 << " месте</b></div>";
                    return;
                }

                if (speek == '(' && s[i] != ')')
                {
                    cout << "<div><b>Ошибка на " << i+1 << " месте</b></div>";
                    return;
                }
                if (speek == '(' && s[i] == ')')
                {
                    delete_el(stack);
                    continue;
                }
                if (speek == '[' && s[i] != ']')
                {
                    cout << "<div><b>Ошибка на " << i+1 << " месте</b></div>";
                    return;
                }
                if (speek == '[' && s[i] == ']')
                {
                    delete_el(stack);
                    continue;
                }
                if (speek == '{' && s[i] != '}')
                {
                    cout << "<div><b>Ошибка на " << i+1 << " месте</b></div>";
                    return;
                }
                if (speek == '{' && s[i] == '}')
                {
                    delete_el(stack);
                    continue;
                }
                if (speek == '<' && s[i] != '>')
                {
                    cout << "<div><b>Ошибка на " << i+1 << " месте</b></div>";
                    return;
                }
                if (speek == '<' && s[i] == '>')
                {
                    delete_el(stack);
                    continue;
                }
            }
        }
        cout << "<div><b>Ошибок нет</b></div>";
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
    cout << "Стек";
}