using System.Collections.Generic;
using Colorful;
using static System.Math;
using static Colorful.Console;

namespace Promptach.Line
{
    public partial class ConsoleLine() : List<ConsoleSide>()
    {
        private int Space
        {
            get
            {
                int space = BufferWidth;
                ForEach(side => space -= side.TotalLength);
                return space;
            }
        }
        public void Write()
        {
            for (int i = 0; i < Count; i++)
            {
                this[i].Write();
                if (i < Count - 1)
                {
                    Console.Write(new string(' ', Max(0, Space)));
                }
            }
        }
    }
}
