add_subdirectory(csv)

# add_subdirectory(json)

add_library(parser_lib STATIC parser.cpp)

target_link_directories(parser_lib PUBLIC
    csv_lib
    # json_lib
)

target_include_directories(parser_lib PUBLIC .)