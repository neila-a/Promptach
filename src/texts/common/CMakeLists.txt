cmake_minimum_required(VERSION 3.16)

project(PromptachTextsCommon LANGUAGES CXX)

add_library(PromptachTextsCommon STATIC
    utils.h
    isInGit.cpp
    run.cpp
    replaceSymbolLink.cpp
)
target_link_libraries(PromptachTextsCommon PUBLIC PromptachSettingsBackend)
install(TARGETS PromptachTextsCommon
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)