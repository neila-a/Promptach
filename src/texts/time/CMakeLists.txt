cmake_minimum_required(VERSION 3.16)

project(PromptachTexts_time LANGUAGES CXX)

add_library(${TextsPrefix}time SHARED
    time.h
)
finalize_target(time)
target_link_libraries(${TextsPrefix}time PRIVATE Qt6::Widgets)