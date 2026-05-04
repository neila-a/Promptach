{
    pkgs,
    ...
}:
pkgs.stdenv.mkDerivation rec {
    pname = "promptach";
    version = "0.4.1";
    src = ./.;

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
        homepage = "https://github.com/neila-a/${pname}";
        license = pkgs.lib.licenses.gpl3Plus;
        platforms = pkgs.lib.platforms.linux;
        mainProgram = "Promptach";
    };
}
