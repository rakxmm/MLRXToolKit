add_library(rx_dataframe STATIC dataframe.cpp)
target_link_libraries(rx_dataframe PUBLIC rx_interface)

target_compile_options(rx_dataframe PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(rx_dataframe PUBLIC -std=c++20)
