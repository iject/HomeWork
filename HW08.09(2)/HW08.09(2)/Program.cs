string str = Console.ReadLine();

char[] s = str.ToCharArray();

int k = 0; // кол-во эл-ов

for (int i = 0; i < s.Length; i++) // находим кол-во эл-ов
{
    if (s[i] == ' ')
    {
        k += 1;
    }
}
k += 1;

double[] mas = new double[k];
for (int i = 0; i < k; i++) mas[i] = 0;

int j = -1;

int pow = -1; // power

for (int i = 0; i < s.Length; i++) // записываем числа в массив
{
    if (pow == -1)
    {
        if ((i != 0) && (i != s.Length - 1)) i++;
        for (int g = i; g < s.Length && s[g] != ' '; g++) pow++;
        j++;
    }
  
    mas[j] += (int)char.GetNumericValue(s[i]) * Math.Pow(10, pow);
    pow--;
}

for (int i = 0; i < k; i++) Console.Write(mas[i].ToString() + ' ');
Console.WriteLine();


for (int i = 0; i < k; i++) // sort
{
    int flag = 1;
    while (flag == 1)
    {
        flag = 0;
        for (var p = 0; p < k - 1; p++)
        {
            if (mas[p] > mas[p + 1])
            {
                double temp = mas[p];
                mas[p] = mas[p + 1];
                mas[p + 1] = temp;
                flag = 1;
            }
        }
    }
}

Console.WriteLine("sorted");
for (int i = 0; i < k; i++) Console.Write(mas[i].ToString() + ' ');
Console.WriteLine();

int c = 1;
int max_c = 1;
int max_last = 0;
for (int i = 0; i < k - 1; i++)
{
    if (mas[i+1] - mas[i] == 1)
    {
        c += 1;
    }
    else
    {
        if (c > max_c)
        {
            max_c = c;
            max_last = i;
        }
        c = 1;
    }
    if (c > max_c && i == k - 2)
    {
        max_c = c;
        max_last = k - 1;
    }
}
Console.Write(mas[max_last - max_c + 1].ToString() + ' ' + mas[max_last].ToString());
