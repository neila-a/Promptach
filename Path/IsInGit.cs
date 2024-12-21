using CliWrap.Buffered;
using static CliWrap.Cli;
using System.Threading.Tasks;
using System;

namespace Promptach
{
    public partial class Path
    {
        private static async Task<bool> IsInGit()
        {
            bool isGit = false;
            try
            {
                BufferedCommandResult isGitResult = await Wrap("git")
                    .WithArguments(["rev-parse", "--is-inside-work-tree"])
                    .ExecuteBufferedAsync();
                isGit = isGitResult.StandardOutput == "true\n";
            }
            catch (Exception)
            {
            }
            return isGit;
        }
    }
}
