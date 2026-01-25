#pragma once

#include "parser/parser.hpp"
namespace rx::parser::csv {

    class CSVParser : public Parser {
        public:
            CSVParser() {};
            ~CSVParser() {};

            void parse(std::string filename) override;
        
    };

} // namespace rx::parser::csv

