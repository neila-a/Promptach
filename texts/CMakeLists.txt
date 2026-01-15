cmake_minimum_required(VERSION 3.16)

project(PromptachBuiltInTexts LANGUAGES CXX)

find_package(KF6Config)

add_library(PromptachBuiltInTextsCommon STATIC
    utils.h
    isInGit.cpp
    run.cpp
)
target_link_libraries(PromptachBuiltInTextsCommon PUBLIC PromptachSettingsBackend)
install(TARGETS PromptachBuiltInTextsCommon
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
set(TextsPrefix "texts_")
function(finalize_target name)
    set_target_properties(${TextsPrefix}${name} PROPERTIES
        OUTPUT_NAME ${name}
        PREFIX ""
    )
    target_link_libraries(${TextsPrefix}${name} PRIVATE PromptachBuiltInTextsCommon)
    target_include_directories(${TextsPrefix}${name} PRIVATE ../${CORE_HEADERS} ../${SETTING_HEADERS})
    install(TARGETS ${TextsPrefix}${name}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/qt-6/plugins/promptach/texts
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endfunction(finalize_target)

add_library(${TextsPrefix}path SHARED
    path.cpp
    texts.h
    utils.h
    gitParentPath.cpp
    replaceSymbolLink.cpp

    pathAliasTable.ui
    pathaliastable.h
    pathaliastable.cpp
)
finalize_target(path)
target_link_libraries(${TextsPrefix}path PRIVATE Qt6::Widgets)

add_library(${TextsPrefix}gitBranch SHARED
    gitBranch.cpp
)
finalize_target(gitBranch)

add_library(${TextsPrefix}gitChildPath SHARED
    utils.h
    gitParentPath.cpp
    gitChildPath.cpp
    replaceSymbolLink.cpp
)
finalize_target(gitChildPath)

add_library(${TextsPrefix}time SHARED
    time.cpp
)
finalize_target(time)
target_link_libraries(${TextsPrefix}time PRIVATE Qt6::Widgets)

add_library(${TextsPrefix}username SHARED
    username.cpp
)
finalize_target(username)
