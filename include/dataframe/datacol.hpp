#pragma once

// Includes
#include <charconv>
#include <dataframe/basecol.hpp>
#include <string>
#include <system_error>
#include <type_traits>
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

            DataCol();

            ~DataCol() = default;

            /** Returns const reference to an elemnt on a such @p index .*/
            // const T& operator[](size_t index) const; 

            void push(const std::string& token) override;

            void print() override {
                
            };

            size_t size() override {
                return m_data.size();
            }

        private:
            std::vector<T> m_data;
    };

    template<typename T>
    DataCol<T>::DataCol() {
    };
    
    template<typename T>
    DataCol<T>::DataCol(size_t size) {
        m_data.reserve(size);
    };

    template<typename T>
    void DataCol<T>::push(const std::string& token) {
        if constexpr (std::is_same_v<T, std::string>) {
            m_data.push_back(token);
        } else if constexpr (std::is_same_v<T, bool>) {
            m_data.push_back((token == "1" || token == "true" || token == "True"));
        } else if constexpr (std::is_arithmetic_v<T>) {
            T value{}; // default value for arithmetic type 0/0.0

            const char* begin = token.data();
            const char* end = token.data() + token.size();
        
            auto result = std::from_chars(begin, end, value);

            if (result.ec != std::errc()) {
                m_data.push_back(T{});
            } else {
                m_data.push_back(value);
            }
        } else {
            // TODO
        }
    }

} // end rx::df