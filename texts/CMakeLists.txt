cmake_minimum_required(VERSION 3.16)

project(PromptachBuiltInTexts LANGUAGES CXX)

find_package(KF6Config)

add_library(PromptachBuiltInTextsCommon SHARED
    utils.h
    isInGit.cpp
    run.cpp
)
target_link_libraries(PromptachBuiltInTextsCommon PUBLIC Qt${QT_VERSION_MAJOR}::Core KF6::ConfigCore)
install(TARGETS PromptachBuiltInTextsCommon
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

function(finalize_target name)
    target_link_libraries(${PromptachBuiltInTextsPrefix}${name} PRIVATE PromptachBuiltInTextsCommon)
    target_include_directories(${PromptachBuiltInTextsPrefix}${name} PRIVATE ../${CORE_HEADERS} ../${SETTING_HEADERS})
    install(TARGETS ${PromptachBuiltInTextsPrefix}${name}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/PromptachTexts
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endfunction(finalize_target)

add_library(${PromptachBuiltInTextsPrefix}path SHARED
    path.cpp
    texts.h
    gitParentPath.cpp
)
finalize_target(path)

add_library(${PromptachBuiltInTextsPrefix}gitBranch SHARED
    gitBranch.cpp
)
finalize_target(gitBranch)

add_library(${PromptachBuiltInTextsPrefix}gitChildPath SHARED
    gitChildPath.cpp
)
finalize_target(gitChildPath)
