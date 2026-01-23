add_library(json_lib STATIC json_parser.cpp json_value.cpp)

target_include_directories(json_lib PUBLIC .)

target_include_directories(json_lib PUBLIC ..)