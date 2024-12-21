using CliWrap.Buffered;
using System.Threading.Tasks;
using static CliWrap.Cli;

namespace Promptach
{
    public partial class Path
    {
        public static async Task<string> GitChild()
        {
            bool isGit = await IsInGit();
            if (isGit)
            {
                BufferedCommandResult prefixResult = await Wrap("git")
                    .WithArguments(["rev-parse", "--show-prefix"])
                    .ExecuteBufferedAsync();
                string output = prefixResult.StandardOutput.Replace("\n", "");
                if (output.Length != 0)
                {
                    return output.Substring(0, output.Length - 1);
                }
            }
            return "";
        }
    }
}