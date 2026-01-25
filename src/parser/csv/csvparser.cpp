#include "parser/parser.hpp"
#include <iostream>
#include <parser/csv/csvparser.hpp>
#include <string>


namespace rx::parser::csv {
    
    void CSVParser::parse(std::string filepath) {
        std::string line; // line in file;

        Parser::openFile(filepath); // opens file

        auto canRead = [this](std::string& line){
            return !!std::getline(m_file, line);
        };

        while(canRead(line)) {
            std::cout << line;
        }
    };


} // end rx::parser::csv