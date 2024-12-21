// See https://aka.ms/new-console-template for more information
using static Promptach.Path;
using static System.Drawing.Color;
using static System.Environment;
using static System.DateTime;
using Promptach.Line;

string parent = await Parent();
string time = Now.ToString("t");
string gitBranch = await GitBranch();
string gitChild = await GitChild();

ConsoleSide left = new()
{
    [parent] = Blue,
    [gitBranch] = Yellow,
    [gitChild] = Orange
};
ConsoleSide right = new()
{
    [UserName] = Aqua,
    [time] = Magenta
};
ConsoleLine line = [left, right];
line.Write();