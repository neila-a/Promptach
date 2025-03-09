cmake_minimum_required(VERSION 3.16)

# Project

set(GLOBAL_PROJECT_NAME "Promptach")
set(GLOBAL_PROJECT_DESCRIPTION "A simple tool for display PS1, advanced.")
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

set(CMAKE_INSTALL_PREFIX /usr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

include(GNUInstallDirs)

# Executable

set(SETTING_HEADERS "settingsbackend")
set(CORE_HEADERS "core")
set(COMMANDLINEPARSER_HEADERS "commandlineparser")

set(PromptachBuiltInTextsPrefix "PromptachBuiltInTexts_")
set(TEXTSDIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/PromptachTexts/")

add_subdirectory(${CORE_HEADERS})
add_subdirectory(settings)
add_subdirectory(${SETTING_HEADERS})
add_subdirectory(${COMMANDLINEPARSER_HEADERS})
add_subdirectory(texts)

# Pack

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTACT "neilaspace@outlook.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Neila")
set(CPACK_DEBIAN_PACKAGE_SECTION "shells")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS "ON")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "konsole-kpart")
set(CPACK_DEBIAN_PACKAGE_RECOMMENDS "git")
include(CPack)

install(TARGETS Promptach PromptachSettings PromptachSettingsBackend PromptachCommandLineParser
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
