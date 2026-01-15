cmake_minimum_required(VERSION 3.16)

project(PromptachTexts_path LANGUAGES CXX)

add_library(${TextsPrefix}path SHARED
    path.cpp
    gitParentPath.cpp

    pathAliasTable.ui
    pathaliastable.h
    pathaliastable.cpp
)
finalize_target(path)
target_link_libraries(${TextsPrefix}path PRIVATE Qt6::Widgets)