cmake_minimum_required(VERSION 3.16)

project(Promptach LANGUAGES CXX)

add_executable(Promptach
  main.cpp
)
target_include_directories(Promptach PRIVATE ../${CORE_HEADERS} ../${COMMANDLINEPARSER_HEADERS})
target_link_libraries(Promptach PRIVATE PromptachCommandLineParser PromptachCore Qt${QT_VERSION_MAJOR}::Core)