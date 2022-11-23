using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace HW10._11._22
{
    public class RMatrix
    {
        // поле
        private int n;
        private int m;
        private Dictionary<int[], string> dict = new Dictionary<int[], string>();

        // индексатор
        public string this [int i, int j]
        {
            get
            {
                int[] a = new int[] { i, j };

                if(i < n && j < m)
                {
                    foreach (var el in dict)
                    {
                        if (a[0] == el.Key[0] && a[1] == el.Key[1])
                        {
                            return el.Value;
                        }
                    }
                    return "0";
                }
                throw new Exception("Не существует такого индекса");
            }
            set
            {
                int[] a = new int[] { i, j };
                foreach (var el in dict)
                {
                    if (a[0] == el.Key[0] && a[1] == el.Key[1])
                    {
                        dict.Remove(el.Key);
                        if (value.ToString() != "0") dict.Add(a, value.ToString());
                        return;
                    }
                }
                if (value.ToString() != "0") dict.Add(a, value.ToString());
            }
        }

        public RMatrix() // c клавы
        {

        }

        public RMatrix(int n, int m) // для рандомного заполнения
        {
            Random r = new Random();
            int k;
            this.n = n;
            this.m = m;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    k = (int)r.NextInt64(0, 2);
                    if(k != 0)
                    {
                        dict.Add(new int[] { i, j }, k.ToString());
                    }
                }
            }
        }

        public void show_d() // вывод dict
        {
            foreach (var i in dict)
            {
                Console.WriteLine($"key: {i.Key[0]}, {i.Key[1]}  value: {i.Value}");
            }
        }

        public void sosed(int j, int i)
        {
            Console.WriteLine($"Соседи {i}, {j}");
            Console.WriteLine($"key: {(i - 1 + n) % n}, {(j - 1 + m) % m}  value: {this[(i - 1 + n) % n, (j - 1 + m) % m]}");
            Console.WriteLine($"key: {i}, {(j - 1 + m) % m}  value: {this[i, (j - 1 + m) % m]}");
            Console.WriteLine($"key: {(i + 1 + n) % n}, {(j - 1 + m) % m}  value: {this[(i + 1 + n) % n, (j - 1 + m) % m]}");
            Console.WriteLine($"key: {(i - 1 + n) % n}, {j}  value: {this[(i - 1 + n) % n, j]}");
            Console.WriteLine($"key: {i}, {j}  value: {this[i, j]}");
            Console.WriteLine($"key: {(i + 1 + n) % n}, {j}  value: {this[(i + 1 + n) % n, j]}");
            Console.WriteLine($"key: {(i - 1 + n) % n}, {(j + 1 + m) % m}  value: {this[(i - 1 + n) % n, (j + 1 + m) % m]}");
            Console.WriteLine($"key: {i}, {(j + 1 + m) % m}  value: {this[i, (j + 1 + m) % m]}");
            Console.WriteLine($"key: {(i + 1 + n) % n}, {(j + 1 + m) % m}  value: {this[(i + 1 + n) % n, (j + 1 + m) % m]}");
        }
    }
}
