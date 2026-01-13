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
function(finalize_target name)
    target_link_libraries(${PromptachBuiltInTextsPrefix}${name} PRIVATE PromptachBuiltInTextsCommon)
    target_include_directories(${PromptachBuiltInTextsPrefix}${name} PRIVATE ../${CORE_HEADERS} ../${SETTING_HEADERS})
    target_compile_definitions(${PromptachBuiltInTextsPrefix}${name} PRIVATE
        PromptachBuiltInTextsPrefix="${PromptachBuiltInTextsPrefix}"
    )
    install(TARGETS ${PromptachBuiltInTextsPrefix}${name}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/PromptachTexts
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endfunction(finalize_target)

add_library(${PromptachBuiltInTextsPrefix}path SHARED
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
target_link_libraries(${PromptachBuiltInTextsPrefix}path PRIVATE Qt6::Widgets)

add_library(${PromptachBuiltInTextsPrefix}gitBranch SHARED
    gitBranch.cpp
)
finalize_target(gitBranch)

add_library(${PromptachBuiltInTextsPrefix}gitChildPath SHARED
    utils.h
    gitParentPath.cpp
    gitChildPath.cpp
    replaceSymbolLink.cpp
)
finalize_target(gitChildPath)

add_library(${PromptachBuiltInTextsPrefix}time SHARED
    time.cpp
)
finalize_target(time)
target_link_libraries(${PromptachBuiltInTextsPrefix}time PRIVATE Qt6::Widgets)

add_library(${PromptachBuiltInTextsPrefix}username SHARED
    username.cpp
)
finalize_target(username)
