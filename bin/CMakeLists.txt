add_executable(main main.cpp)


target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(main PUBLIC -std=c++20)


# 1. Definujeme cieľ, ktorý fyzicky skopíruje priečinok
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${DATA_DIR}"
        "$<TARGET_FILE_DIR:main>/../data"
    COMMENT "Copying data to output folder!"
)

target_link_libraries(
    main
    PRIVATE
        rx_interface
        rx_dataframe
        rx_parser
        rx_parser_csv
)