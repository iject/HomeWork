using HW10._11._22;

RMatrix m = new RMatrix(6, 6);
m.show_d();

Console.WriteLine(m[1, 2]);
m[1, 2] = "0";
m[1, 0] = "str";
m.show_d();

m.sosed(0, 0);
