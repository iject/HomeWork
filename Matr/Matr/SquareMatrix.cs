using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Matr
{
    public class SquareMatrix : Matrix
    {
        public SquareMatrix() : base() // c клавы
        {

        }
        public SquareMatrix(int n) : base(n, n) // для рандомного заполнения
        {

        }
        public SquareMatrix(Matrix a) : base(a) // для копирования
        {
            
        }

        public SquareMatrix(int n, int m, bool flag = true) : base(n, m, flag) // для заполнения 0-ми
        {
            
        }

        public SquareMatrix(string filename) : base(filename) // заполнение из файла
        {
            // можно сделать проверку, а потом base вызывать?
            if (N != M)
            {
                throw new Exception("В файле записана не квадратная матрица");
            }
        }


        public double Det()
        {
            double sum = 0;
            for (int i = 0; i < this.N; i++)
            {
                if (this.N == 1)
                {
                    return this[0, 0];
                }
                else
                {
                    SquareMatrix a = new SquareMatrix(this.del(0,i));
                    if(i % 2 == 0) sum += this[0, i] * a.Det();
                    else sum -= this[0, i] * a.Det();
                }
            }
            return Math.Round(sum, 2);
        }

        public void Gauss()
        {
            if (Det() != 0) return;

            for (int j = 0; j < M; j++)
            {
                for (int i = 0; i < N; i++)
                {

                }
            }
        }

        public static SquareMatrix operator +(SquareMatrix a, SquareMatrix b)
        {
            return new SquareMatrix((Matrix)a + b);
        }

        public static SquareMatrix operator -(SquareMatrix a, SquareMatrix b)
        {
            return new SquareMatrix((Matrix)a - b);
        }

        public static SquareMatrix operator *(SquareMatrix a, double b)
        {
            return new SquareMatrix((Matrix)a * b);
        }

        public static SquareMatrix operator /(SquareMatrix a, double b)
        {
            return new SquareMatrix((Matrix)a / b);
        }

        public static SquareMatrix operator *(SquareMatrix a, SquareMatrix b)
        {
            return new SquareMatrix((Matrix)a * b);
        }
    }
}
