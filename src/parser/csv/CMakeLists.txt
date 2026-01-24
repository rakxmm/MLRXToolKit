add_library(rx_parser_csv STATIC csv_parser.cpp)
target_link_libraries(rx_parser_csv PUBLIC rx_interface)
