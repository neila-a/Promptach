using CliWrap.Buffered;
using System.Threading.Tasks;
using static CliWrap.Cli;

namespace Promptach
{
    public partial class Path
    {
        public static async Task<string> GitBranch()
        {
            bool isGit = await IsInGit();
            if (isGit)
            {
                BufferedCommandResult prefixResult = await Wrap("bash")
                    .WithArguments(["-c", "source /usr/lib/git-core/git-sh-prompt && __git_ps1 %s"])
                    .ExecuteBufferedAsync();
                string output = prefixResult.StandardOutput;
                return output;
            }
            return "";
        }
    }
}
