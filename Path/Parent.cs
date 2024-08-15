using static System.Drawing.Color;
using static Colorful.Console;
using System.Threading.Tasks;
using SmallestCSV;
using static System.Environment;
using System.Collections.Generic;
using System.IO;

namespace Promptach
{
    public partial class Path
    {
        public static async Task Parent()
        {
            string str = await GitParent();
            using (var stream = new StreamReader(GetEnvironmentVariable("HOME") + "/.config/pathAliases.csv")) 
            {
                var parser = new SmallestCSVParser(stream);
                while (true) 
                {
                    List<string>? columns = parser.ReadNextRow();
                    if (columns == null) 
                    {
                        break;
                    }
                    str = str.Replace(columns[0], columns[1]);
                }
            }
            Write(str, Blue);
        }
    }
}
