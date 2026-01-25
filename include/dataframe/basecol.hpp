#pragma once

#include <cstddef>
namespace rx::df {
    class BaseCol {
        public:
            virtual ~BaseCol() = 0;

            virtual size_t size() = 0;

            virtual void print() = 0;
        protected:
            size_t m_size;
    };


} // end rx::df
