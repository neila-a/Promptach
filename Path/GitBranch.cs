using CliWrap;
using CliWrap.Buffered;
using System.Threading.Tasks;
using static CliWrap.Cli;
using static System.Drawing.Color;
using static Colorful.Console;

namespace Promptach
{
    public partial class Path
    {
        public static async Task GitBranch()
        {
            bool isGit = await IsInGit();
            if (isGit)
            {
                var prefixResult = await Wrap("bash")
                    .WithArguments(["-c", "source /usr/lib/git-core/git-sh-prompt && __git_ps1 %s"])
                    .ExecuteBufferedAsync();
                string output = prefixResult.StandardOutput;
                Write(output, Yellow);
                Write(" ");
            }
        }
    }
}
