{
  description = "A pluggable, highly configurable prompt generator.";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    systems.url = "github:nix-systems/x86_64-linux";
  };
  outputs =
    {
      flake-utils,
      self,
      systems,
      nixpkgs,
    }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
      };
      commonInputs = {
        nativeBuildInputs = with pkgs; [
          kdePackages.wrapQtAppsHook
          cmake
          ninja
          gettext
        ];
        buildInputs =
          let
            normalPackages = with pkgs; [
              glfw
              glm
              libGL
              libGLU
            ];
            kdePackages = with pkgs.kdePackages; [
              kconfig
              qtbase
              qttools
            ];
          in
          normalPackages ++ kdePackages;
      };
    in
    rec {
      packages."${system}".default =
        let
          fs = pkgs.lib.fileset;
          sourceFiles = fs.difference (fs.gitTracked ./.) (
            fs.unions [
              .github/.
              .gitignore/.
              README.md/.
              LICENSE.md/.
            ]
          );
        in

        pkgs.stdenv.mkDerivation {
          pname = "promptach";
          version = "0.4.0";

          inherit (commonInputs) nativeBuildInputs buildInputs;

          src = fs.toSource {
            root = ./.;
            fileset = sourceFiles;
          };

          patchPhase = ''
            lrelease ./src/settings/PromptachSettings_zh_CN.ts -qm ./src/settings/PromptachSettings_zh_CN.qm
          '';

          installPhase = ''
            ninja install
            cp -r install/* $out/
          '';

          meta = {
            homepage = "https://github.com/neila-a/Promptach";
            license = pkgs.lib.licenses.gpl3Plus;
            platforms = pkgs.lib.platforms.linux;
            mainProgram = "Promptach";
          };
        };
      devShells."${system}".default = pkgs.mkShell {
        inherit (commonInputs) nativeBuildInputs buildInputs;
      };
    };
}
