using class_tochek;

Point a = new Point();
Point b = new Point(9, 8, 7);
Point c = new Point(1, 12, -49);
Point d = new Point(4, 9, -1);
Point f = new Point(-852, 20, 7);

Console.WriteLine(a.X);
Console.WriteLine($"b {b}");
Console.WriteLine($"c {c}");
Console.WriteLine($"d {d}");

Console.WriteLine("distance(c, d): {0}", Point.distance(c, d));
Console.WriteLine("distance_r(c): {0}", Point.distance_r(c));
Console.WriteLine("equation(c, d): {0}", Point.equation(c, d));
Console.WriteLine("smult(d, f): {0}", Point.smult(d, f));
Console.WriteLine("vmult(d, f): {0}", Point.vmult(d, f));
Console.WriteLine("equation_pl(c, d, f): {0}", Point.equation_pl(c, d, f));
Console.WriteLine(d + f);
