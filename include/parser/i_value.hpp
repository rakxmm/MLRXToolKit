#pragma once
#include <string>

namespace rx::parser {
    class IValue {
        public:
            virtual std::string str() = 0;
            virtual ~IValue() = default;
    };

    class NumberVal : IValue {
        public:
            NumberVal(long double val) : m_val(val) {};

            std::string str() override {
                return std::to_string(m_val);
            };

        private:
            long double m_val;
    };


    class BoolVal : IValue {
        public:
            BoolVal(bool val) : m_val(val) {};

            std::string str() override {
                return m_val ? "true" : "false";
            };
        private:
            bool m_val;
    };


    class StringVal : IValue {
        public:
            StringVal(std::string& s) : m_val(std::move(s)) {};

            std::string str() override {
                return m_val;
            };
        
        private:
            std::string m_val;
    };



} // end rx::parser