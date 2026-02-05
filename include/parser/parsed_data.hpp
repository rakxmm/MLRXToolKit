#pragma once

#include <string>
#include <unordered_map>
#include <dataframe/basecol.hpp>
namespace rx::parser {
    enum struct DataType {
        FLOAT,
        INT,
        BOOL,
        STRING,
        ARRAY_INT,
        ARRAY_FLOAT,
        ARRAY_BOOL,
        ARRAY_STRING
    };
    
    struct ParsedData {

        ParsedData() {};
        ~ParsedData() {};

        bool addColumn(df::BaseCol* col, const std::string col_name);

    private:
        std::unordered_map<std::string, df::BaseCol*> m_cols;
        std::vector<df::BaseCol*> m_cols_datatypes;
        size_t m_col_count = 0;

    };

} // end rx::parser