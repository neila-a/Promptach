cmake_minimum_required(VERSION 3.16)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project

set(GLOBAL_PROJECT_NAME "Promptach")
set(GLOBAL_PROJECT_DESCRIPTION "A pluggable, highly configurable prompt generator.")
set(GLOBAL_PROJECT_VERSION 0.4.0)

project(${GLOBAL_PROJECT_NAME}
    LANGUAGES CXX
    VERSION ${GLOBAL_PROJECT_VERSION}
    DESCRIPTION ${GLOBAL_PROJECT_DESCRIPTION}
    HOMEPAGE_URL "https://github.com/neila-a/Promptach"
)

# Dependencies

set(CMAKE_INSTALL_PREFIX ./install)
find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs)
include(GNUInstallDirs) # GNU must after KDE
set(CMAKE_INSTALL_LIBDIR lib)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools Quick)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools Quick)
find_package(KF6Config)
find_package(KF6KCMUtils)

# Executable

set(SETTING_HEADERS "settingsbackend")
set(CORE_HEADERS "core")
set(COMMANDLINEPARSER_HEADERS "commandlineparser")

add_subdirectory(src)

install(TARGETS Promptach PromptachSettingsBackend PromptachCommandLineParser
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
