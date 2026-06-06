{
    config,
    lib,
    pkgs,
    ...
}:
with lib;
let
    cfg = config.programs.promptach;
in
{
    options.programs.promptach = {
        enable = mkEnableOption "the promptach program";
        package = mkOption {
            type = types.package;
            default = import ./package.nix pkgs;
            description = "promptach package to use.";
        };
        linestart = mkOption {
            type = types.str;
            default = "> ";
            description = "start character at new line.";
        };
    };

    config = mkIf cfg.enable {
        environment.variables = {
            PROMPT_COMMAND = "export PS1='${cfg.linestart}'; ${cfg.package}/bin/Promptach";
        };
    };
}
