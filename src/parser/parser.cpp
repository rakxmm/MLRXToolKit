#include "parser.hpp"
#include "i_value.hpp"
#include <cctype>
#include <stdexcept>
#include <string>
#include <regex>


namespace rx::parser {
    void Parser::consumeWhiteSpace() {
        if(!m_text) throw std::runtime_error("There is nothing to consume, because of null text!");
        while(std::isspace(m_current_char)) {
            m_index++;
            if (m_index >= m_text->size()) {
                m_current_char = 0;
                break;
            }
            m_current_char = (*m_text)[m_index];
        }
    };

    
    bool Parser::isNumber(std::string token )
    {   
        // +/- is optional, at least one digit, the part with floating point is optional => '.' and at least one digit
        return std::regex_match( token, std::regex( ( "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?" ) ) );
    }

    

    Parser::BoolOption Parser::getBool(std::string token) {
        if (token == "true" || token == "True") return BoolOption::TRUE;
        if (token == "false" || token == "False") return BoolOption::FALSE;
        return BoolOption::NONE;
    }

    IValue* Parser::parseWord(const std::string& word) {
        
            switch (getBool(word)) {
                case Parser::BoolOption::TRUE:
                    return new Bool(true);
                case Parser::BoolOption::FALSE:
                    return new Bool(false);
                default:
                    break;
            };
            
            if(isNumber(word)) {
                return new Number(std::stold(word));
            }

            return new String(word);
        
    }


} // end namespace