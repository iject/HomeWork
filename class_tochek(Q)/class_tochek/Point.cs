using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace class_tochek
{
    public class Point
    {
        public double X { get; set; }
        public double Y { get; set; }
        public double Z { get; set; }

        public Point()
        {

        }

        public Point(double x, double y, double z)
        {
            X = x;
            Y = y;
            Z = z;
        }

        protected static double distance(Point a, Point b) // расстояние от одной точки до другой
        {
            return Math.Sqrt(Math.Pow(a.X - b.X, 2) + Math.Pow(a.Y - b.Y, 2) + Math.Pow(a.Z - b.Z, 2));
        }

        protected static double distance_r(Point a) // расстояние от точки до начала координат(использую как модуль для вектора)
        {
            return distance(a, new Point(0, 0, 0));
        }

        protected static double[] line(Point a, Point b) // ур-е прямой
        {
            double r_x = b.X - a.X;
            double r_y = b.Y - a.Y;
            double r_z = b.Z - a.Z;
            double[] line = { r_x, r_y, r_z };
            return line;
            // return $"(x - {a.X}) / {r_x} = (y - {a.Y}) / {r_y} = (z - {a.Z}) / {r_z}";
        }

        protected static double[] plane(Point A, Point B, Point C) // ур-е плоскости
        {
            double k1 = (B.Y - A.Y) * (C.Z - A.Z) + (A.Y - C.Y) * (B.Z - A.Z);
            double k2 = (C.X - A.X) * (B.Z - A.Z) + (A.X - B.X) * (C.Z - A.Z);
            double k3 = (B.X - A.X) * (C.Y - A.Y) + (A.X - C.X) * (B.Y - A.Y);
            double k4 = ((B.Y - A.Y) * (C.Z - A.Z) + (A.Y - C.Y) * (B.Z - A.Z)) * (-A.X) +
                ((C.X - A.X) * (B.Z - A.Z) + (A.X - B.X) * (C.Z - A.Z)) * (-A.Y) +
                ((B.X - A.X) * (C.Y - A.Y) + (A.X - C.X) * (B.Y - A.Y)) * (-A.Z);
            double[] line = {k1, k2, k3, k4};
            return line;
            // return $"{k1}x + {k2}y + {k3}z + {k4}";
        }

        public static double? cosfi(Point a, Point b) // cos углa между векторами
        {
            if (a != new Point(0, 0, 0) && b != new Point(0, 0, 0))
                return (a.X * b.X + a.Y * b.Y + a.Z * b.Z) / (distance_r(a) * distance_r(b));
            return null;
        }

        protected static double? angle(Point a, Point b) // угол между векторами
        {
            double? cos = cosfi(a, b);
            if (cos is not null)
                return Math.Acos(Convert.ToDouble(cos));
            return cos;
        }

        public static double smult(Point a, Point b) // скалярное произведение векторов
        {
            return (a.X * b.X + a.Y * b.Y + a.Z * b.Z);
        }

        public static Point vmult(Point a, Point b) // векторное произведение векторов
        {
            return new Point(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
        }

        /*public static double check_oneside(Point point, Point vector) // проверка на расположение точки отн-о вектора
        {

            return new Point(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
        }*/

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append($"({X}, {Y}, {Z})");
            return sb.ToString();
        }

        public static Point operator +(Point a, Point b) => new Point(a.X + b.X, a.Y + b.Y, a.Z + b.Z); // сложение векторов
        public static Point operator -(Point a, Point b) => new Point(a.X - b.X, a.Y - b.Y, a.Z - b.Z); // вычитание векторов
        public static bool operator ==(Point a, Point b) => a.X == b.X && a.Y == b.Y && a.Z == b.Z;
        public static bool operator !=(Point a, Point b) => a.X != b.X || a.Y != b.Y || a.Z != b.Z;

    }
}