{
    description = "A pluggable, highly configurable prompt generator.";

    inputs = {
        nixpkgs.url = "git+https://mirror.nju.edu.cn/git/nixpkgs.git?ref=nixpkgs-unstable&shallow=1";
        flake-utils.url = "https://proxy.gitwarp.top/https://github.com/numtide/flake-utils/archive/refs/heads/master.zip";
    };

    outputs =
        {
            self,
            nixpkgs,
            flake-utils,
        }:
        let
            packages = flake-utils.lib.eachDefaultSystem (
                system:
                let
                    pkgs = import nixpkgs {
                        inherit system;
                    };
                in
                {
                    packages = rec {
                        promptach = import ./package.nix pkgs;
                        default = promptach;
                    };

                    devShells.default = pkgs.mkShell {
                        packages = with pkgs; [
                            cmake
                            ninja
                            kdePackages.wrapQtAppsHook
                            kdePackages.qtbase
                            kdePackages.kconfig
                            kdePackages.qttools
                        ];

                        inputsFrom = [
                            self.packages.${system}.default
                        ];
                    };
                }
            );
        in
        packages
        // {
            nixosModules = rec {
                promptach = ./nixosmodule.nix;
                default = promptach;
            };
        };
}
