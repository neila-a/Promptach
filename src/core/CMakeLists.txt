cmake_minimum_required(VERSION 3.16)

project(PromptachCore LANGUAGES CXX)

add_library(PromptachCore STATIC
  write.h write.cpp
  textinterface.h textloader.h

  line/consoleline.h line/consoleline.cpp
  line/consoleside.h line/consoleside.cpp
)
target_include_directories(PromptachCore PRIVATE ../${SETTING_HEADERS})
target_link_libraries(PromptachCore PRIVATE PromptachSettingsBackend)