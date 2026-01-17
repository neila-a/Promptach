cmake_minimum_required(VERSION 3.16)

project(PromptachSettings VERSION 0.1 LANGUAGES CXX)

set(TS_FILES PromptachSettings_zh_CN.ts)

set(PROJECT_SOURCES
    main.cpp

    settingswindow.cpp settingswindow.h settingswindow.ui
    ${TS_FILES}
)

qt_add_executable(PromptachSettings
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}

    previewer.h previewer.cpp
    settings.qrc
    textsview.cpp
    textsview_buttons.cpp
)

target_include_directories(PromptachSettings PRIVATE ../${SETTING_HEADERS} ../${COMMANDLINEPARSER_HEADERS} ../${CORE_HEADERS})
target_link_libraries(PromptachSettings PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets

    PromptachSettingsBackend
    PromptachCommandLineParser

    KF6::Service
    KF6::Parts
    KF6::CoreAddons
)

set_target_properties(PromptachSettings PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(PromptachSettings)