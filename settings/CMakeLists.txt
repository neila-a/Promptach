cmake_minimum_required(VERSION 3.16)

project(PromptachSettings VERSION 0.1 LANGUAGES CXX)

find_package(KF6Service)
find_package(KF6Parts)
find_package(KF6CoreAddons)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES PromptachSettings_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp

        settingswindow.cpp settingswindow.h settingswindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PromptachSettings
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        pathaliastable.cpp

        previewer.h previewer.cpp
        settings.qrc
        textsview.cpp
        textsview_buttons.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PromptachSettings APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(PromptachSettings SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PromptachSettings
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_include_directories(PromptachSettings PRIVATE ../${SETTING_HEADERS} ../${COMMANDLINEPARSER_HEADERS} ../${CORE_HEADERS})
target_link_libraries(PromptachSettings PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets

    PromptachSettingsBackend
    PromptachCommandLineParser

    KF6::Service
    KF6::Parts
    KF6::CoreAddons
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER io.neila.Promptach.Settings)
endif()
set_target_properties(PromptachSettings PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PromptachSettings)
endif()

target_compile_definitions(PromptachSettings PRIVATE
    TEXTSDIR="${TEXTSDIR}"
    PromptachBuiltInTextsPrefix="${PromptachBuiltInTextsPrefix}"
)
