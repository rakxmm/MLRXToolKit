#pragma once

// Includes
#include <dataframe/basecol.hpp>
#include <vector>
// End includes

namespace rx::df {
    /**
        Represents type column.
    */
    template<typename T>
    class DataCol : public BaseCol {
        public: 
            /** Creates column of certain data and reserves vector of @p size .*/
            DataCol(size_t size);

            ~DataCol() = default;

            /** Returns const reference to an elemnt on a such @p index .*/
            const T& operator[](size_t index) const; 

            void push(T& t);


        private:
            std::vector<T> m_data;
    };
} // end rx::df