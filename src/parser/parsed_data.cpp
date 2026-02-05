#include "parser/parsed_data.hpp"
#include <stdexcept>    

namespace rx::parser {

    bool ParsedData::addColumn(df::BaseCol* col, const std::string col_name) {
        if (!m_cols[col_name]) {
            m_cols[col_name] = col;
            m_datatypes.push_back(col); 
            m_col_count++;
            return true;
        } 
        return false;
    }
    
    df::BaseCol* ParsedData::operator[](size_t index) const { // may be an error due the 'const'
        if (index >= m_datatypes.size()) throw std::out_of_range("Index out of range!");
        return m_datatypes.at(index); 
    }

} // end rx::parser