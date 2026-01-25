#pragma once

#include <string>
#include <unordered_map>
#include <dataframe/basecol.hpp>
namespace rx::parser {
    struct ParsedData {

        ParsedData() {};
        ~ParsedData() {};

        std::unordered_map<std::string, df::BaseCol*> m_cols;
        size_t m_colCount;

    };

} // end rx::parser