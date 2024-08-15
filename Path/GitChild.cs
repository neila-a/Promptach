using CliWrap;
using CliWrap.Buffered;
using System.Threading.Tasks;
using static System.Drawing.Color;
using static Colorful.Console;
using static CliWrap.Cli;

namespace Promptach
{
    public partial class Path
    {
        public static async Task GitChild()
        {
            bool isGit = await IsInGit();
            if (isGit)
            {
                var prefixResult = await Wrap("git")
                    .WithArguments(["rev-parse", "--show-prefix"])
                    .ExecuteBufferedAsync();
                string output = prefixResult.StandardOutput.Replace("\n", "");
                if (output.Length != 0)
                {
                    Write(output.Substring(0, output.Length - 1), Orange);
                }
            }
        }
    }
}