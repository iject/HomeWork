using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace class_tochek
{
    class Point
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

        public static double distance(Point a, Point b) // расстояние от одной точки до другой
        {
            return Math.Sqrt(Math.Pow(a.X - b.X, 2)  + Math.Pow(a.Y - b.Y, 2) + Math.Pow(a.Z - b.Z, 2));
        }

        public static double distance_r(Point a) // расстояние от точки до начала координат
        {
            return Math.Sqrt(Math.Pow(a.X, 2)  + Math.Pow(a.Y, 2) + Math.Pow(a.Z, 2));
        }

        public static string equation(Point a, Point b) // ур-е прямой
        {
            double r_x = b.X - a.X;
            double r_y = b.Y - a.Y;
            double r_z = b.Z - a.Z;
            return $"(x - {a.X}) / {r_x} = (y - {a.Y}) / {r_y} = (z - {a.Z}) / {r_z}";
            /*return $"{r_y * r_z / r_x}x - {r_x * r_z / r_y}y + {r_y * r_x / r_z}z +" +
                $" {-(r_y * r_z / r_x) * a.X + (r_x * r_z / r_y) * a.Y - (r_y * r_x / r_z) * a.Z} = 0";*/
        }

        public static string equation_pl(Point A, Point B, Point C) // ур-е плоскости
        {
            double k1 = (B.Y - A.Y) * (C.Z - A.Z) + (A.Y - C.Y) * (B.Z - A.Z);
            double k2 = (C.X - A.X) * (B.Z - A.Z) + (A.X - B.X) * (C.Z - A.Z);
            double k3 = (B.X - A.X) * (C.Y - A.Y) + (A.X - C.X) * (B.Y - A.Y);
            double k4 = ((B.Y - A.Y) * (C.Z - A.Z) + (A.Y - C.Y) * (B.Z - A.Z)) * (-A.X) +
                ((C.X - A.X) * (B.Z - A.Z) + (A.X - B.X) * (C.Z - A.Z)) * (-A.Y) +
                ((B.X - A.X) * (C.Y - A.Y) + (A.X - C.X) * (B.Y - A.Y)) * (-A.Z);
            return $"{k1}x + {k2}y + {k3}z + {k4}";
        }

        public static double cosfi(Point a, Point b) // угол между векторами
        {
            return (a.X * b.X + a.Y * b.Y + a.Z * b.Z) / (distance_r(a) * distance_r(b));
        }

        public static double smult(Point a, Point b) // скалярное произведение векторов
        {
            return (a.X * b.X + a.Y * b.Y + a.Z * b.Z);
        }

        public static Point vmult(Point a, Point b) // векторное произведение векторов
        {
            return new Point(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
            // distance_r(a) * distance_r(b) * Math.Sqrt(Math.Round(1 - Math.Pow(cosfi(a, b), 2), 3));
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append($"({X}, {Y}, {Z})");
            return sb.ToString();
        }

        public static Point operator +(Point a, Point b) => new Point(a.X + b.X, a.Y + b.Y, a.Z + b.Z); // сложение векторов

    }
}
