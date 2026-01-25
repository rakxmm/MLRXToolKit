add_library(rx_parser_csv STATIC csvparser.cpp)

target_compile_options(rx_parser_csv PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(rx_parser_csv PUBLIC -std=c++20)

target_link_libraries(rx_parser_csv PUBLIC rx_interface)
