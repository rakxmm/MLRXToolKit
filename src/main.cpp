#include "parser/csv/csv_parser.hpp"
#include <filesystem>
#include <iostream>

#define LOG(x) std::cout << std::setprecision(3) << x << std::endl

int main (int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    // std::filesystem::path exePath = std::filesystem::absolute(argv[0]).parent_path();
    // std::filesystem::current_path(exePath);

    std::string string = "true,\"member\",id";

    rx::parser::csv::CSVParser parser;
    parser.parseLine(string);
    // parser.parse("data/finance.csv");

   

 
    return 0;
}