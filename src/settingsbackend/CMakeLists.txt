cmake_minimum_required(VERSION 3.16)

project(PromptachSettingsBackend LANGUAGES CXX)

add_library(PromptachSettingsBackend STATIC
  PromptachSettingsBackend_global.h
  settings.cpp
  settings.h
)

target_link_libraries(PromptachSettingsBackend PUBLIC Qt${QT_VERSION_MAJOR}::Core KF6::ConfigCore)