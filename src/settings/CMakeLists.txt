cmake_minimum_required(VERSION 3.16)

project(PromptachSettings VERSION 0.1 LANGUAGES CXX)

kcmutils_add_qml_kcm(promptachsettings)
target_sources(promptachsettings PRIVATE
    main.cpp

    settingswindow.cpp settingswindow.h settingswindow.ui
    promptachsettings.h promptachsettings.cpp
    textsview.cpp textsview_buttons.cpp

    PromptachSettings_zh_CN.ts
    settings.qrc
)
target_include_directories(promptachsettings PRIVATE ../${SETTING_HEADERS} ../${COMMANDLINEPARSER_HEADERS} ../${CORE_HEADERS})
target_link_libraries(promptachsettings PRIVATE
    Qt6::Widgets
    Qt6::Quick
    KF6::KCMUtils

    PromptachSettingsBackend
    PromptachCore
    PromptachCommandLineParser
)