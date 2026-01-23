#include "parser.hpp"
#include <cctype>
#include <stdexcept>
#include <string>



namespace rx::parser {
    void Parser::consumeWhiteSpace() {
        if(!m_text) throw std::runtime_error("There is nothing to consumoe, because of empty m_text!");
        while(std::isspace(m_current_char)) {
            m_index++;
            if (m_index >= m_text->size()) {
                m_current_char = 0;
                break;
            }
            m_current_char = (*m_text)[m_index];
        }
    };



} // end namespace