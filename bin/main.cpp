

#include <parser/csv/csvparser.hpp>


int main (int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    rx::parser::csv::CSVParser parser;
    parser.parse("finance.csv");

 
    return 0;
}