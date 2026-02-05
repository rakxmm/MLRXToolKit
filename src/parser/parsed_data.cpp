#include <parser/parsed_data.hpp>

namespace rx::parser {

    bool ParsedData::addColumn(df::BaseCol* col, const std::string col_name) {
        if (!m_cols[col_name]) {
            m_cols[col_name] = col;
            m_cols_datatypes.push_back(col); 
            return true;
        } 
        return false;      
    }

} // end rx::parser