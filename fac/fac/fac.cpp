#include "Header.h"

//void strcut_p(char*& a, char*& s)
//{
//    int x = 0;
//    for (int i = 0; i < 9; x++, i++)
//    {
//        s[i] = a[strlen(a) - 10 + x];
//        if (a[strlen(a) - 10 + x] == '\0') return;
//    }
//    s[9] = '\0';
//    a[strlen(a) - 10] = '\0';
//}

void add_n(list2& list, int data, int pos)
{
    if (!pos)
    {
        list.first->x = data; // Возвращаем значение первого элемента
        return;
    }

    if (pos == list.count - 1)
    {
        list.last->x = data; // Возвращаем значение последнего элемента
        return;
    }
        // Иначе ищем элемент с нужным номером
    int p = 1;
    // Определяем предпочтительное направление поиска
    bool fwd = pos <= list.count / 2;
    elem* curr;
    // Находим стартовый элемент
    if (fwd)
        curr = list.first->next;
    else {
        curr = list.last->prev;
        // Корректируем номер искомого элемента в зависимости от направления поиска
        pos = list.count - pos - 1;
    }
    while (curr && p < pos) {
        p++;
        // Переходим вперед или назад в зависимости от направления поиска
        curr = fwd ? curr->next : curr->prev;
    }
    // Здесь указатель находится на искомом элементе
    curr->x = data;
}

void strcut_p(char*& a, char& s)
{
    s = a[strlen(a) - 1];

    a[strlen(a) - 1] = '\0';
}

void fac(list2& list, int a)
{
    add(list, 1);
    for (int i = 2; i <= a; ++i)
    {
        //char* s_c = new char[10];
        int temp = 0;
        for (int j = 0; j < list.count; j++)
        {
            int curr = *get(list, j) * i + temp;
            if (curr > 9)
            {
                /*char s[10];
                sprintf_s(s, "%d", curr);
                strcpy_s(s_c, 10, s);
                char c;

                strcut_p(s_c, c);
                int c_int = c - '0';*/

                add_n(list, curr % 10, j);
                //show_list(list);
                temp = curr / 10;
            }
            else
            {
                add_n(list, curr, j);
                //show_list(list);
                temp = temp / 10;
            }
        }
        while (temp > 9)
        {
            add(list, temp % 10);
            temp /= 10;
        }
        if (temp != 0)
        {
            add(list, temp);
            //show_list(list);
        }
    }
}

int main()
{
    list2 list;
    
   /* for (int i = 0; i < 100; ++i)
    {
        cout << "i = " << i << ": ";
        fac(list, i);
        show_list(list, true);
        clear(list);
    }*/

    fac(list, 500);
    show_list(list, true);
}