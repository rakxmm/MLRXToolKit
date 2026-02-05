add_library(rx_parser STATIC parsed_data.cpp parser.cpp)

add_subdirectory(csv)
# add_subdirectory(json)

target_compile_options(rx_parser PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(rx_parser PUBLIC -std=c++20)


target_link_libraries(rx_parser 
    PUBLIC 
        rx_interface
)