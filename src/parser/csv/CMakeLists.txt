add_library(csv_lib STATIC csv_parser.cpp csv_value.cpp)

target_include_directories(csv_lib PUBLIC .)

target_include_directories(csv_lib PUBLIC ..)
