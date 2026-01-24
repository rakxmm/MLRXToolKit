#pragma once


#include "parsed_data.hpp"
namespace rx::parser {
    class Parser {
        public:
            virtual ~Parser() = default;

            virtual ParsedData getParsedData() = 0;
        protected:
            ParsedData m_parsedData;
    };  
    
} // end rx::parser

