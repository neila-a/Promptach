cmake_minimum_required(VERSION 3.16)

project(PromptachCore LANGUAGES CXX)

add_executable(Promptach
  main.cpp

  line/consoleline.h line/consoleline.cpp
  line/consoleside.h line/consoleside.cpp
)
target_include_directories(Promptach PRIVATE ../${SETTING_HEADERS} ../${COMMANDLINEPARSER_HEADERS})
target_link_libraries(Promptach PRIVATE PromptachSettingsBackend PromptachCommandLineParser)
target_compile_definitions(Promptach PRIVATE
    TEXTSDIR="${TEXTSDIR}"
    PromptachBuiltInTextsPrefix="${PromptachBuiltInTextsPrefix}"
)
