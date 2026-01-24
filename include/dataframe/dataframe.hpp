#pragma once
#include <string>
#include <unordered_map>
#include <dataframe/i_column.hpp>

namespace rx::df {

    /**
        Owner of a data.
    */
    class DataFrame {
    

        private:
            std::unordered_map<std::string, BaseCol*> m_data;
    };

} // end rx::df
