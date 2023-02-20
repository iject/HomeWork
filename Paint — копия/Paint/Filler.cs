using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Paint
{
    public class Filler
    {
        private Color New_color;
        private Color Old_color;
        static Bitmap bm;
        MouseEventArgs E;

        public Filler(Color new_color, Bitmap _bm, MouseEventArgs e)
        {
            New_color = new_color;
            bm = _bm;
            Old_color = bm.GetPixel(e.X, e.Y);
            E = e;
        }
        public void Fill()
        {
            if (Old_color != New_color)
            {
                int x = E.X;
                int y = E.Y;
                Stack<Point> pixel = new Stack<Point>();
                pixel.Push(new Point(x, y));
                bm.SetPixel(x, y, New_color);
                while (pixel.Count > 0)
                {
                    Point pt = (Point)pixel.Pop();
                    if (pt.X > 0 && pt.Y > 0 && pt.X < bm.Width - 1 && pt.Y < bm.Height - 1)
                    {
                        Validate(pixel, pt.X - 1, pt.Y);
                        Validate(pixel, pt.X, pt.Y - 1);
                        Validate(pixel, pt.X + 1, pt.Y);
                        Validate(pixel, pt.X, pt.Y + 1);
                    }
                }

            }
        }
        private void Validate(Stack<Point> sp, int x, int y)
        {
            Color cx = bm.GetPixel(x, y);
            if (cx == Old_color)
            {
                sp.Push(new Point(x, y));
                bm.SetPixel(x, y, New_color);
            }
        }
    }
}
