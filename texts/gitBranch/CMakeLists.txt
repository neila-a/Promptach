cmake_minimum_required(VERSION 3.16)

project(PromptachTexts_gitBranch LANGUAGES CXX)

add_library(${TextsPrefix}gitBranch SHARED
    gitBranch.cpp
)
finalize_target(gitBranch)