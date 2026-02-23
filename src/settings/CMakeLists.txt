cmake_minimum_required(VERSION 3.16)

project(PromptachSettings VERSION 0.1 LANGUAGES CXX)

set(TS_FILES PromptachSettings_zh_CN.ts)

kcmutils_add_qml_kcm(promptachsettings)
target_sources(promptachsettings PRIVATE
    main.cpp

    settingswindow.cpp settingswindow.h settingswindow.ui
    promptachsettings.h promptachsettings.cpp
    ${TS_FILES}

    settings.qrc
    textsview.cpp textsview_buttons.cpp
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

set_target_properties(promptachsettings PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(promptachsettings)