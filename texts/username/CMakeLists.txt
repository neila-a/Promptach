cmake_minimum_required(VERSION 3.16)

project(PromptachTexts_username LANGUAGES CXX)

add_library(${TextsPrefix}username SHARED
    username.cpp
)
finalize_target(username)