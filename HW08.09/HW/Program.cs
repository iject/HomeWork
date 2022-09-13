string a = Console.ReadLine();
string b = Console.ReadLine();

string sort(string a)
{
    int flag = 1;
    char[] s = a.ToCharArray();
    while (flag == 1)
    {
        flag = 0;
        for (var i = 0; i < s.Length - 1; i++)
        {
            if (s[i] < s[i + 1])
            {
                char temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                flag = 1;
            }
        }
    }
    
    return new string(s);
}


if (a.Length == b.Length)
{
    if (sort(a) == sort(b))
    {
        Console.WriteLine("YES");
    }
    else { Console.WriteLine("NO"); }
}
else { Console.WriteLine("NO"); }