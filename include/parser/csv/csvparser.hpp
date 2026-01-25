#pragma once

#include "parser/parser.hpp"
namespace rx::parser::csv {

    class CSVParser : public Parser {
        public:
            CSVParser() {m_separator = ',';};
            ~CSVParser() {};

            void parse(std::string filename) override;

            void setSeparator(char sep) {m_separator = sep;}
        private:
            char m_separator;

            //todo
            parseLine(std::string& line);

    };

} // namespace rx::parser::csv

