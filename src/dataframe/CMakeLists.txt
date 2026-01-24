add_library(rx_dataframe STATIC dataframe.cpp)
add_library(rx::dataframe ALIAS rx_dataframe)

target_link_libraries(rx_dataframe 
    PUBLIC 
        rx_interface
        # rx::math
)