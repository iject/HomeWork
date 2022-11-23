using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Reflection.PortableExecutable;
using System.Text;
using System.Threading.Tasks;

namespace Matr
{
    public class Matrix
    {
        // поле
        private int n;
        private int m;
        private double[,] matr;

        // св-ва
        public int N{ get => n; set => n = value; }
        public int M{ get => m; set => m = value; }
        public double[,] Matr { get => matr; set => matr = value; }

        public Matrix() // c клавы
        {

        }

        public Matrix(int n, int m) // для рандомного заполнения
        {
            Random r = new Random();
            this.n = n;
            this.m = m;
            double[,] matr = new double[n, m];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matr[i, j] = r.NextInt64(100, 999) / 10.0;
                }
            }
            this.matr = matr;
        }

        public Matrix(Matrix a) // для копирования
        {
            this.n = a.n;
            this.m = a.m;
            double[,] matr = new double[a.n, a.m];

            for (int i = 0; i < a.n; i++)
            {
                for (int j = 0; j < a.m; j++)
                {
                    matr[i, j] = a.matr[i, j];
                }
            }
            this.matr = matr;
        }

        public Matrix(int n, int m, bool flag = true) // для заполнения 0-ми
        {
            this.n = n;
            this.m = m;
            double[,] matr = new double[n, m];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matr[i, j] = 0;
                }
            }
            this.matr = matr;
        }

        public Matrix(string filename) // заполнение из файла
        {

            string[] f = File.ReadAllLines(filename);
            this.n = f.Length;
            this.m = f[0].Split().Length;
            double[,] matr = new double[n, m];
            for (int i = 0; i < n; i++)
            {
                string[] temp = f[i].Split();
                for (int j = 0; j < m; j++)
                {
                    matr[i, j] = double.Parse((temp[j]));
                }
            }
            this.matr = matr;

            /*using (var reader = new StreamReader(filename, Encoding.UTF8))
            {
                string s = reader.ReadLine();
                string[] words = s.Split(new char[] { ' ' });
                int i = 0;

                this.n = int.Parse(words[0]);
                this.m = int.Parse(words[1]);
                double[,] matr = new double[n, m];

                while (!reader.EndOfStream)
                {
                    s = reader.ReadLine();
                    words = s.Split(new char[] { ' ' });
                    for (int j = 0; j < words.Length; j++)
                    {
                        matr[i, j] = int.Parse(words[j]);
                        
                    }
                    i++;
                }

                this.matr = matr;
            }*/
        }

        public void show() // вывод матрицы
        {
            for (int i = 0; i < this.n; i++)
            {
                for (int j = 0; j < this.m; j++)
                {
                    Console.Write($"{matr[i, j]}\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        public void T() // транспонирование матрицы
        {
            Matrix c = new Matrix(this.m, this.n, true);
            for (int i = 0; i < this.n; i++)
            {
                for (int j = 0; j < this.m; j++)
                {
                    c.matr[j, i] = this.matr[i,j];
                }
            }
            this.n = c.n;
            this.m = c.m;
            this.matr = c.matr;
        }

        public Matrix del(int i, int j) // удаление i строки и j столбца
        {
            Matrix buf = new Matrix(this.N - 1, this.M - 1, true);
            for (int k = 0; k < this.N; k++)
            {
                if (k == i) continue;
                int i_k = k;
                if (k > i) i_k = k - 1;
                for (int l = 0; l < this.M; l++)
                {
                    if (l == j) continue;
                    int j_l = l;
                    if (l > j) j_l = l - 1;
                    buf.matr[i_k, j_l] = this.matr[k, l];
                }
            }
            return buf;
        }

        public double this[int i, int j] // ввод и вывод эл-а из i строки и j столбца
        {
            get => this.matr[i, j];
            set => this.matr[i, j] = value;
        }

        public static Matrix operator +(Matrix a, Matrix b)
        {
            if (a.n == b.n && a.m == b.m)
            {
                Matrix buf = new Matrix(a.n, a.m, true);
                for (int i = 0; i < a.n; i++)
                {
                    for (int j = 0; j < a.m; j++)
                    {
                        buf.matr[i, j] = Math.Round(a.matr[i, j] + b.matr[i, j], 2);
                    }
                }
                return buf;
            }
            throw new Exception("Размерность матриц не совпадает");
        }

        public static Matrix operator -(Matrix a, Matrix b)
        {
            Matrix buf = new Matrix(a.n, a.m, true);
            if (a.n == b.n && a.m == b.m)
            {
                for (int i = 0; i < a.n; i++)
                {
                    for (int j = 0; j < a.m; j++)
                    {
                        buf.matr[i, j] = Math.Round(a.matr[i, j] - b.matr[i, j], 2);
                    }
                }
                return buf;
            }
            throw new Exception("Размерность матриц не совпадает");
        }

        public static Matrix operator *(Matrix a,double b)
        {
            // можно ли поменять тип на SquareMatrix, если в рез-те кв. матрица?
            Matrix buf = new Matrix(a.n, a.m, true);
            for (int i = 0; i < a.n; i++)
                {
                    for (int j = 0; j < a.m; j++)
                    {
                        buf.matr[i, j] = Math.Round(a.matr[i, j] * b, 2);
                    }
                }
                return buf;
        }

        public static Matrix operator /(Matrix a,double b)
        {
            if (b == 0) throw new Exception("На ноль делить нельзя");

            Matrix buf = new Matrix(a.n, a.m, true);
            for (int i = 0; i < a.n; i++)
                {
                    for (int j = 0; j < a.m; j++)
                    {
                        buf.matr[i, j] = Math.Round(a.matr[i, j] / b, 2);
                    }
                }
            return buf;
        }

        public static Matrix operator *(Matrix a, Matrix b)
        {
            if(a.m == b.n)
            {
                Matrix buf = new Matrix(a.n, b.m, true);
                for (int i = 0; i < a.n; i++)
                    {
                        for (int j = 0; j < b.m; j++)
                        {
                            for (int k = 0; k < a.m; k++)
                            {
                                buf.matr[i, j] = Math.Round(a.matr[i, k] * b.matr[k, j] + buf.matr[i, j], 1);
                            }
                        }
                    }
                    return buf;
            }
            throw new Exception("Кол-во столбцов первой матрицы не равно кол-ву строк второй матрицы");
        }
    }
}