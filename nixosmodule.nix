{
    config,
    lib,
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
            default = import ./package.nix;
            description = "promptach package to use.";
        };
    };

    config = mkIf cfg.enable {
        environment.variables = {
            PROMPT_COMMAND = "${cfg.package}/bin/Promptach";
        };
    };
}
