using System.Threading.Tasks;
using SmallestCSV;
using static System.Environment;
using System.Collections.Generic;
using System.IO;

namespace Promptach
{
    public partial class Path
    {
        public static async Task<string> Parent()
        {
            string str = await GitParent();
            try {
                using StreamReader stream = new(GetEnvironmentVariable("HOME") + "/.config/pathAliases.csv");
                SmallestCSVParser parser = new(stream);
                while (true)
                {
                    List<string>? columns = parser.ReadNextRow();
                    if (columns == null)
                    {
                        break;
                    }
                    str = str.Replace(columns[0], columns[1]);
                }
            } catch (FileNotFoundException) {}
            return str;
        }
    }
}
