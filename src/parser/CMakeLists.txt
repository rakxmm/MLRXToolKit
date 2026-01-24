add_library(rx_parser STATIC parser.cpp)
add_library(rx::parser ALIAS rx_parser)

# add_subdirectory(csv)
# add_subdirectory(json)

target_link_libraries(rx_parser 
    PUBLIC 
        rx_interface
        # rx::parser::csv
        # rx::parser::json
)