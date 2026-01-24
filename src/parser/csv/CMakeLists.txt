add_library(rx_parser_csv STATIC csv_parser.cpp)
add_library(rx::parser::csv ALIAS rx_parser_csv)

target_link_libraries(rx_parser_csv PUBLIC rx_interface)
