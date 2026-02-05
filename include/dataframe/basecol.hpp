#pragma once

#include <cstddef>
#include <string>
namespace rx::df {
    class BaseCol {
        public:
            virtual ~BaseCol() = 0;

            virtual size_t size() = 0;

            virtual void print() = 0;

            virtual void push(const std::string& token) = 0;
    };
    inline BaseCol::~BaseCol() {};

} // end rx::df
