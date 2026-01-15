cmake_minimum_required(VERSION 3.16)

project(PromptachTexts_gitChildPath LANGUAGES CXX)

add_library(${TextsPrefix}gitChildPath SHARED
    gitChildPath.cpp
)
finalize_target(gitChildPath)