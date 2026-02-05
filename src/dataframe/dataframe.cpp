#include "dataframe/basecol.hpp"
#include "parser/parsed_data.hpp"
#include <dataframe/dataframe.hpp>
#include <stdexcept>


#define NOT_IMPLEMENTED "TODO: Not implemented yet."

namespace rx::df {
    DataFrame::DataFrame() {
    };

    DataFrame::~DataFrame() {
    };

    void DataFrame::print() {
        throw std::runtime_error(NOT_IMPLEMENTED);
    };

    const BaseCol* DataFrame::operator[](std::string col_name) {
        return m_data[col_name];
    };

    void DataFrame::read_csv(std::string filepath) {
        (void)filepath;
        /**  
            Parser will be called to open file and parse it.
            In certain cycles, parser release Parsed data and DataFrame
            will load it to itself.
        */
        throw std::runtime_error(NOT_IMPLEMENTED);
    }

    void consume(parser::ParsedData&& chunk) {
        (void)chunk;
        throw std::runtime_error(NOT_IMPLEMENTED);
    }

} // end rx::df