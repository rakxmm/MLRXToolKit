add_executable(main main.cpp)


target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(main PUBLIC -std=c++20)


target_link_libraries(
    main
    PRIVATE
        rx_dataframe
        # rx_parser
)