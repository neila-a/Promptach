cmake_minimum_required(VERSION 3.16)

# Project

set(GLOBAL_PROJECT_NAME "Promptach")
set(GLOBAL_PROJECT_DESCRIPTION "A pluggable, highly configurable prompt generator.")
set(GLOBAL_PROJECT_VERSION 0.3.0)

project(${GLOBAL_PROJECT_NAME}
    LANGUAGES CXX
    VERSION ${GLOBAL_PROJECT_VERSION}
    DESCRIPTION ${GLOBAL_PROJECT_DESCRIPTION}
    HOMEPAGE_URL "https://github.com/neila-a/Promptach"
)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INSTALL_PREFIX ./install)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets LinguistTools)
find_package(KF6Config)

include(GNUInstallDirs)
set(CMAKE_INSTALL_LIBDIR lib)

# Executable

set(SETTING_HEADERS "settingsbackend")
set(CORE_HEADERS "core")
set(COMMANDLINEPARSER_HEADERS "commandlineparser")

add_subdirectory(${CORE_HEADERS})
add_subdirectory(settings)
add_subdirectory(${SETTING_HEADERS})
add_subdirectory(${COMMANDLINEPARSER_HEADERS})
add_subdirectory(texts)

install(TARGETS Promptach PromptachSettings PromptachSettingsBackend PromptachCommandLineParser
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
