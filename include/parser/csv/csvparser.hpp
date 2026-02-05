#pragma once

#include "parser/parsed_data.hpp"
#include "parser/parser.hpp"
namespace rx::parser::csv {

    class CSVParser : public Parser {
        public:
            CSVParser() : m_separator(','), m_hasHeader(true){};
            ~CSVParser() {};

            void parse(std::string filename) override;

            void setSeparator(char sep) {m_separator = sep;}

            void setHasHeader(bool hasHeader) {m_hasHeader = hasHeader;};

        private:
            std::vector<std::string> getTokens(std::string& line);

            std::vector<rx::parser::DataType> getTokensTypes(const std::vector<std::string>& tokens) const;

            char m_separator; // default = ','
            bool m_hasHeader; // default = true (TODO: different type for better memory performance)

    };

} // namespace rx::parser::csv

