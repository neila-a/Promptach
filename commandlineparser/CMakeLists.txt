cmake_minimum_required(VERSION 3.16)

project(PromptachCommandLineParser LANGUAGES CXX)

add_library(PromptachCommandLineParser STATIC
  PromptachCommandLineParser_global.h
  promptachcommandlineparser.cpp
  promptachcommandlineparser.h

)

target_link_libraries(PromptachCommandLineParser PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(PromptachCommandLineParser PRIVATE
    PROMPTACHCOMMANDLINEPARSER_LIBRARY
    _PROJECT_NAME="${GLOBAL_PROJECT_NAME}"
    _PROJECT_DESCRIPTION="${GLOBAL_PROJECT_DESCRIPTION}"
    _PROJECT_VERSION="${GLOBAL_PROJECT_VERSION}"
)
