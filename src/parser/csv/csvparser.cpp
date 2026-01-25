#include "parser/parser.hpp"
#include <iostream>
#include <parser/csv/csvparser.hpp>
#include <regex>
#include <stdexcept>
#include <string>


namespace rx::parser::csv {
    
    void CSVParser::parse(std::string filename) {
        
        std::regex csvPattern("\\.[cC][sS][vV]$");
        if (!std::regex_search(filename, csvPattern)) throw std::runtime_error("Wrong file extension/suffix.");
        
        std::string line; // line in file;
        Parser::openFile(filename); // opens file

        auto canRead = [this](std::string& line){
            return !!std::getline(m_file, line);
        };

        while(canRead(line)) {
            std::cout << line;
        }
    };


} // end rx::parser::csv