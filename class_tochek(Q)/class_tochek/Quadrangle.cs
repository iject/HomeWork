using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace class_tochek
{
    public class Quadrangle : Point
    {
        public Point A { get; set; } = new Point(0, 0, 0);
        public Point B { get; set; } = new Point(0, 0, 0);
        public Point C { get; set; } = new Point(0, 0, 0);
        public Point D { get; set; } = new Point(0, 0, 0);

        public Point d1 = new Point(0, 0, 0);
        public Point d2 = new Point(0, 0, 0);


        public Quadrangle()
        {
        }
        public Quadrangle(Point a, Point b, Point c, Point d) 
        {
            if (check_plane(a, b, c, d))
            {
                A = a;
                B = b;
                C = c;
                D = d;
                d1 = a - c;
                d2 = b - d;
            }
        }

        private static double S_triangular(Point vect_a, Point vect_b) // нахождение S 3-ка
        {
            return Math.Round(0.5 * distance_r(vect_a) * distance_r(vect_b) *
                    Math.Sin(Convert.ToDouble(angle(vect_a, vect_b))), 3);
        }

        public static double S(Quadrangle q) // #1
        {
            if (check_bulge(q))
            {
                /*return Math.Round(0.5 * len_d(q)[0] * len_d(q)[1] * 
                    Math.Sin(Convert.ToDouble(angle(q.d1, q.d2))), 3);*/
                return S_triangular(q.d1, q.d2);
            }

            int i = find_vertex_bulge(q);
            Point[] mas = { q.A, q.B, q.C, q.D };
            Point vl_1 = mas[(i + 3) % 4] - mas[(i + 2) % 4];
            Point vr_1 = mas[(i + 5) % 4] - mas[(i + 2) % 4];
            Point vl_2 = mas[(i + 3) % 4] - mas[i];
            Point vr_2 = mas[(i + 5) % 4] - mas[i];

            double S_1 = S_triangular(vl_1, vr_1);
            double S_2 = S_triangular(vl_2, vr_2);
            //Console.WriteLine("S1 = {0}, S2 = {1}", S_1, S_2);
            return S_1 - S_2;

        }

        public static double P(Quadrangle q) // #2
        {
            return distance_r(q.A - q.B) + distance_r(q.B - q.C)
                + distance_r(q.C - q.D) + distance_r(q.D - q.A);
        }

        public static double[] len_d(Quadrangle q) // #3
        {
            double[] line = { distance_r(q.d1), distance_r(q.d2) };
            return line;
        }

        public static bool check_plane(Point a, Point b, Point c, Point d) // #8
        {
            double[] k = plane(a, b, c);
            if (k[0] * d.X + k[1] * d.Y + k[2] * d.Z + k[3] == 0)
            {
                return true;
            }
            return false;
        }

        public static bool check_bulge(Quadrangle q) // #4
        {
            int i = find_vertex_bulge(q);
            if (i == -1)
            {
                return true;
            }
            return false;
        }

        private static int find_vertex_bulge(Quadrangle q) // нахождение вершины невыпуклого 4-ка
        {
            Point AB = q.B - q.A;
            Point BC = q.C - q.B;
            Point CD = q.D - q.C;
            Point DA = q.A - q.D;

            Point t1 = vmult(AB, BC);
            Point t2 = vmult(BC, CD);
            Point t3 = vmult(CD, DA);
            Point t4 = vmult(DA, AB);

            if (cosfi(t1, t2) * cosfi(t1, t3) * cosfi(t1, t4) > 0)
            {
                return -1;
            }
            if (cosfi(t1, t2) == cosfi(t1, t3))
            {
                return 1;
            }
            if (cosfi(t1, t2) == -1)
            {
                return 2;
            }
            if (cosfi(t1, t3) == -1)
            {
                return 3;
            }
            return 0;
        }

        public static string type_Q(Quadrangle q) // #7
        {
            Point AB = q.B - q.A;
            Point BC = q.C - q.B;
            Point CD = q.D - q.C;
            Point DA = q.A - q.D;

            if (Math.Sin(Math.Round(Math.Sin(Convert.ToDouble(angle(AB, CD))), 3)) == 0 &&
                Math.Round(Math.Sin(Convert.ToDouble(angle(BC, DA))), 3) == 0) // проверка на || 4 противоположных сторон
            {
                if (smult(AB, BC) == 0 && smult(AB, DA) == 0)
                {
                    if (distance_r(AB) == distance_r(BC) && distance_r(BC) == distance_r(CD) &&
                        distance_r(CD) == distance_r(DA) && distance_r(DA) == distance_r(AB))
                    {
                        return "Квадрат";
                    }
                    return "Прямоугольник";
                }
                if (distance_r(AB) == distance_r(BC) && distance_r(BC) == distance_r(CD) &&
                        distance_r(CD) == distance_r(DA) && distance_r(DA) == distance_r(AB))
                {
                    return "Ромб";
                }
                return "Параллелограмм";
            }
            if (Math.Sin(Math.Round(Math.Sin(Convert.ToDouble(angle(AB, CD))), 3)) == 0 ||
                Math.Round(Math.Sin(Convert.ToDouble(angle(BC, DA))), 3) == 0) // проверка на || 2 противоположных сторон
                {
                return "Трапеция";
            }
            return "Четырехугольник";
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append($"({A}, {B}, {C}, {D})");
            return sb.ToString();
        }
    }
}
