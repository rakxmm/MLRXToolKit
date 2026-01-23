#ifndef PARSER_CSV_CSVPARSER_HPP
#define PARSER_CSV_CSVPARSER_HPP

#include "../parser.hpp"
#include <vector>

namespace rx::parser::csv {
 
    class CSVParser : public Parser {
        public:
            ~CSVParser() {};

            // Reads CSV file and puts it in the CSV formated Object! 
            IValue* parse(const std::string& filepath) override;
            
            // Parses line into different columns separated by ',' if not said differently.
            std::vector<IValue*> parseLine(std::string& line);

        protected:

        private:
            
    };     
    
} // end namespace

#endif