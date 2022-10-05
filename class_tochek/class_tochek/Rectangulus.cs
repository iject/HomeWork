using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace class_tochek
{
    public class Rectangulus : Point
    {
        public Point A { get; set; } = new Point (0, 0, 0);
        public Point B { get; set; } = new Point(0, 0, 0);
        public Point C { get; set; } = new Point(0, 0, 0);
        public Point D { get; set; } = new Point(0, 0, 0);

        public Rectangulus (Point a, Point b, Point c)
        {
            check(a, b, c);
        }

        public Rectangulus (Point a, Point b, Point c, Point d)
        {
            check(a, b, c);
            if (!(D.X == d.X && D.Y == d.Y && D.Z == d.Z)) A = B = C = D = new Point(0, 0, 0);
        }

        private void check(Point a, Point b, Point c)
        {
            if (smult(a - b, c - b) == 0)
            {
                A = a;
                B = b;
                C = c;
                D = b + (a - b) + (c - b);
            }
            else if (smult(b - a, c - a) == 0)
            {
                A = a;
                B = b;
                C = c;
                D = a + (b - a) + (c - a);
            }
            else if (smult(a - c, b - c) == 0)
            {
                A = a;
                B = b;
                C = c;
                D = c + (b - c) + (a - c);
            }
        }

        public static double S(Rectangulus r)
        {
            if (smult(r.A - r.D, r.C - r.D) == 0) return distance(r.A, r.D) * distance(r.C, r.D);
            if (smult(r.A - r.D, r.B - r.D) == 0) return distance(r.A, r.D) * distance(r.B, r.D);
            return distance(r.B, r.D) * distance(r.C, r.D);
        }
        public static double P(Rectangulus r)
        {
            if (smult(r.A - r.D, r.C - r.D) == 0) return 2 * (distance(r.A, r.D) + S(r)/ distance(r.A, r.D));
            if (smult(r.A - r.D, r.B - r.D) == 0) return 2 * (distance(r.A, r.D) + S(r) / distance(r.A, r.D));
            return 2 * (distance(r.B, r.D) + S(r) / distance(r.B, r.D));
        }
        public static double len_d(Rectangulus r)
        {
            return Math.Sqrt(2*S(r));
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append($"({A}, {B}, {C}, {D})");
            return sb.ToString();
        }
    }
}
