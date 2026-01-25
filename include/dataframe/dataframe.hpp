#pragma once
#include <string>
#include <unordered_map>
#include <dataframe/basecol.hpp>
#include <parser/parsed_data.hpp>

namespace rx::df {

    /**
        Owner of a data.
    */
    class DataFrame {
        DataFrame();

        ~DataFrame();

        void print();

        void read_csv(std::string filepath);

        const BaseCol* operator[](const std::string col_name);

        // Maybe private
        void consume(parser::ParsedData&& chunk);

        private:
            std::unordered_map<std::string, BaseCol*> m_data;
    };

} // end rx::df
