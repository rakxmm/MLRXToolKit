add_library(rx_parser_json STATIC json_parser.cpp)
add_library(rx::parser::json ALIAS rx_parser_json)

target_link_libraries(rx_parser_json PUBLIC rx_interface)
