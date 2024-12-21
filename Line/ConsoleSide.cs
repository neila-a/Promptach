using System.Collections.Generic;
using System.Drawing;
using Colorful;

namespace Promptach.Line
{
    public partial class ConsoleSide() : Dictionary<string, Color>
    {
        public int TotalLength
        {
            get
            {
                KeyCollection strings = Keys;
                int totalLength = 0;
                foreach (string key in strings)
                {
                    totalLength += key.Length + 1;
                }
                return totalLength - 1;
            }
        }
        public void Write()
        {
            List<string> keys = [.. Keys];
            for (int i = 0; i < Keys.Count; i++)
            {
                string key = keys[i];
                Console.Write(key, this[key]);
                if (i < Keys.Count - 1)
                {
                    Console.Write(" ");
                }
            }
        }
    }
}
