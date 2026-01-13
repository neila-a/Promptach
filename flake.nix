{
  description = "A pluggable, highly configurable prompt generator written in C++.";
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
        nativeBuildInputs = [
          pkgs.kdePackages.wrapQtAppsHook
          pkgs.cmake
          pkgs.ninja
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
              kcoreaddons
              kservice
              kparts
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
          version = "0.3.0";

          inherit (commonInputs) nativeBuildInputs buildInputs;

          src = fs.toSource {
            root = ./.;
            fileset = sourceFiles;
          };

          patchPhase = ''
            lrelease ./settings/PromptachSettings_zh_CN.ts -qm ./settings/PromptachSettings_zh_CN.qm
          '';

          installPhase = ''
            ninja install
            cp -r install/* $out/
          '';
        };
      devShells."${system}".default = pkgs.mkShell {
        inherit (commonInputs) nativeBuildInputs buildInputs;
      };
    };
}
