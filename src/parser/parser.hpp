#pragma once

#include <string>
#include "i_value.hpp"

namespace rx::parser {

    class Parser {
    public:
        
        virtual ~Parser() = 0;
        
        // Parses the file into hierarchical system, starting with root @atribute m_output
        virtual IValue* parse(const std::string& part) = 0;

        
    
    protected:
        // Consumes all white spaces, until non-whitespace occurs
        void consumeWhiteSpace(); 

        bool isNumber(std::string token);

        enum class BoolOption {
            TRUE,
            FALSE,
            NONE
        };


        BoolOption getBool(std::string token);
        
        IValue* parseWord(const std::string& word);
        

        // Root
        IValue* m_output; 

        // Char at current index
        char m_current_char; 
        size_t m_index;

        // Whole file output is in this text;
        std::string* m_text;
    };

    inline Parser::~Parser() {};
    
} // end namespace

