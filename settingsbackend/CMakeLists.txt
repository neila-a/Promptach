cmake_minimum_required(VERSION 3.16)

project(PromptachSettingsBackend LANGUAGES CXX)

find_package(KF6Config)

add_library(PromptachSettingsBackend STATIC
  PromptachSettingsBackend_global.h
  settings.cpp
  settings.h
  builtintextslist.h
)

target_link_libraries(PromptachSettingsBackend PUBLIC Qt${QT_VERSION_MAJOR}::Core KF6::ConfigCore)