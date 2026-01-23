#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include "column.hpp"
#include <cstddef>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

namespace df {


class DataFrame {
public:
    DataFrame(std::vector<df::IColumn*> cols);

    IColumn* operator[](std::string col_name);
    
    friend std::ostream& operator<<(std::ostream& ost, const DataFrame& df); 
    
private:
    std::vector<std::unique_ptr<df::IColumn>> m_cols;
    std::unordered_map<std::string, IColumn*> m_mapCols;
    
    size_t m_Length;
};




} // end namespace


#endif