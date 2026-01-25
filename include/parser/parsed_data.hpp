#pragma once

#include "dataframe/i_column.hpp"
#include <string>
#include <unordered_map>
namespace rx::parser {
    struct ParsedData {

        ParsedData() {};
        ~ParsedData() {};

        std::unordered_map<std::string, df::BaseCol*> m_cols;
        size_t m_colCount;

    };

} // end rx::parser