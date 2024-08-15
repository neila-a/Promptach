using CliWrap;
using CliWrap.Buffered;
using System.Threading.Tasks;
using static System.IO.Directory;
using static CliWrap.Cli;

namespace Promptach
{
    public partial class Path
    {
        private static async Task<string> GitParent()
        {
            bool isGit = await IsInGit();
            if (isGit)
            {
                var prefixResult = await Wrap("git")
                    .WithArguments(["rev-parse", "--show-toplevel"])
                    .ExecuteBufferedAsync();
                string output = prefixResult.StandardOutput;
                return output.Replace("\n", " ");
            }
            else
            {
                return GetCurrentDirectory().TrimEnd();
            }
        }
    }
}
