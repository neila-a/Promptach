cmake_minimum_required(VERSION 3.16)

project(Promptach
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "A simple tool for display PS1, advanced."
    HOMEPAGE_URL "https://github.com/neila-a/Promptach"
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Promptach
  main.cpp

  line/consoleline.h line/consoleline.cpp
  line/consoleside.h line/consoleside.cpp

  text/texts.h
  text/gitParentPath.cpp
  text/gitChildPath.cpp
  text/gitBranch.cpp
  text/path.cpp

  util/utils.h
  util/run.cpp
  util/isInGit.cpp
  util/settings.h util/settings.cpp
)
target_link_libraries(Promptach Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Promptach
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Pack
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTANT "neilaspace@outlook.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Neila")
set(CPACK_DEBIAN_PACKAGE_SECTION "shells")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
include(CPack)
