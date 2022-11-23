using Matr;

Matrix a = new Matrix(3, 3);
Console.WriteLine("a:");
a.show();

Matrix b = new Matrix(3, 3);
Console.WriteLine("b:");
b.show();

Matrix a_copy = new Matrix(a);
Console.WriteLine("a_copy:");
a_copy.show();

Matrix zero = new Matrix(2, 3, true);
Console.WriteLine("zero:");
zero.show();

Matrix file_matrix = new Matrix("text.txt");
Console.WriteLine("file_matrix:");
file_matrix.show();


Console.WriteLine("a + b:");
(a + b).show();
Console.WriteLine("a - b:");
(a - b).show();
Console.WriteLine("a * 5:");
(a * 5).show();
Console.WriteLine("a / 5:");
(a / 5).show();
Console.WriteLine("a * b:");
(a * b).show();

Console.WriteLine("a.T");
a.T();
a.show();

Console.WriteLine(a[1, 1]);

SquareMatrix s_a = new SquareMatrix(3);
Console.WriteLine("s_a");
s_a.show();


SquareMatrix s_b = new SquareMatrix(3);
Console.WriteLine("s_b");
s_b.show();

SquareMatrix s_file = new SquareMatrix("text.txt");
Console.WriteLine("s_file {0}", s_file.GetType());
s_file.show();

Console.WriteLine("s_a + s_b:");
(s_a + s_b).show();
Console.WriteLine((s_a + s_b).GetType());
Console.WriteLine("s_a - s_b:");
(s_a - s_b).show();
Console.WriteLine("s_a * 5:");
(s_a * 5).show();
Console.WriteLine("s_a / 5:");
(s_a / 5).show();
Console.WriteLine("s_a * s_b:");
(s_a * s_b).show();

Console.WriteLine("s_a.T");
s_a.T();
s_a.show();
Console.WriteLine(s_a[1, 1]);


Console.WriteLine("s_a.det");
Console.WriteLine(s_a.Det());
