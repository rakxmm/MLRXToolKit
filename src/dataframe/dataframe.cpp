#include "dataframe.hpp"
#include "column.hpp"
#include <memory>
#include <stdexcept>


namespace df {

    DataFrame::DataFrame(std::vector<df::IColumn*> cols) {
        bool isFirst = true;
        for(IColumn* col : cols) {
            if (isFirst) {
                m_Length = col->size();
                isFirst = false;
            }
            
            if (m_Length != col->size()) {
                throw std::runtime_error("Different sizes of columns in DataFrame init!");
            }
            m_mapCols[col->name()] = col;
            m_cols.push_back(std::unique_ptr<IColumn>(col));
        }   
    }

    IColumn* DataFrame::operator[](std::string col_name) {
        return m_mapCols[col_name];
    }


    std::ostream& operator<<(std::ostream& ost, const DataFrame& df) {
        std::string s = "Dataframe:\n";
        ost << s;

        // Header
        for ( const std::unique_ptr<IColumn>& c : df.m_cols) {
            ost << '\t' + c->name();
            if(c == df.m_cols.back()) {
                ost << '\n';
            }
        }

        // Data
        for(size_t i = 0; i < df.m_Length; i++) {
            for (const std::unique_ptr<IColumn>& c : df.m_cols) {
                ost << '\t' + c->at(i);
                if(c == df.m_cols.back()) {
                    ost << '\n';
                }
            }
        }
        return ost;
    }; 


} // end namespace