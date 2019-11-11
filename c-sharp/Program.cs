using System;
using System.Drawing;

namespace c_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            TestClass t = new TestClass();
            Console.WriteLine($"Hello World! {t.ReturnMessage()}");
        }
    }
}
