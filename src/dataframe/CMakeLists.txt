add_library(df_lib STATIC dataframe.cpp)

target_include_directories(df_lib PUBLIC .)

target_include_directories(df_lib PUBLIC ..)

