cmake_minimum_required(VERSION 3.16)

project(PromptachTexts LANGUAGES CXX)

set(TextsPrefix "texts_")

add_subdirectory(common)

function(finalize_target name)
    set_target_properties(${TextsPrefix}${name} PROPERTIES
        OUTPUT_NAME ${name}
        PREFIX ""
    )
    target_link_libraries(${TextsPrefix}${name} PRIVATE PromptachTextsCommon)
    target_include_directories(${TextsPrefix}${name} PRIVATE ../../${CORE_HEADERS} ../../${SETTING_HEADERS} ../common)
    install(TARGETS ${TextsPrefix}${name}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/qt-6/plugins/promptach/texts
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endfunction(finalize_target)

add_subdirectory(path)
add_subdirectory(gitBranch)
add_subdirectory(gitChildPath)
add_subdirectory(time)
add_subdirectory(username)