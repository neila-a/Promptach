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
        flake-utils.lib.eachDefaultSystem (
            system:
            let
                name = "promptach";
                version = "0.4.0";
                homepage = "https://github.com/neila-a/${name}";
                pkgs = import nixpkgs {
                    inherit system;
                };
                nativeBuildInputs = with pkgs; [
                    cmake
                    ninja
                    kdePackages.wrapQtAppsHook
                ];

                buildInputs = with pkgs.kdePackages; [
                    qtbase
                    kconfig
                    qttools
                ];
            in
            {
                packages = rec {
                    promptach = pkgs.stdenv.mkDerivation {
                        pname = name;
                        version = version;
                        src = ./.;

                        nativeBuildInputs = nativeBuildInputs;
                        buildInputs = buildInputs;

                        cmakeFlags = [
                            "-DCMAKE_INSTALL_PREFIX=${placeholder "out"}"
                        ];

                        prePatch = ''
                            lrelease ./src/settings/PromptachSettings_zh_CN.ts -qm ./src/settings/PromptachSettings_zh_CN.qm
                        '';

                        installPhase = ''
                            runHook preInstall
                            ninja install
                            runHook postInstall
                        '';

                        meta = {
                            homepage = homepage;
                            license = pkgs.lib.licenses.gpl3Plus;
                            platforms = pkgs.lib.platforms.linux;
                            mainProgram = "${name}_app";
                        };
                    };
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

                    inputsFrom = [ self.packages.${system}.default ];
                };
            }
        );
}
