#pragma once

#include <string>
#include <unordered_map>
#include <dataframe/basecol.hpp>
#include <vector>

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
    
    class ParsedData {
    
        public:
            ParsedData() {};
            ~ParsedData() {};

            bool addColumn(df::BaseCol* col, const std::string col_name);
            
            size_t colCount() {return m_col_count;}

            df::BaseCol* operator[](size_t index) const;

        private:
            std::unordered_map<std::string, df::BaseCol*> m_cols;
            std::vector<df::BaseCol*> m_datatypes;
            size_t m_col_count = 0;
    };

    
} // end rx::parser