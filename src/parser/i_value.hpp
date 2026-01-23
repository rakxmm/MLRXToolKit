#ifndef PARSER_IVALUE_HPP
#define PARSER_IVALUE_HPP



#include <string>

namespace rx::parser {
    class IValue {
        public:
            virtual std::string str() = 0;
            virtual ~IValue() = 0;
    };

    inline IValue::~IValue() {};


    class Number : public IValue {
        public:
            Number(long double v) : m_val(v) {};
            int asInt() {return m_val;}
            long double get() {return m_val;};
            std::string str() override {return std::to_string(m_val);};
        private:
            long double m_val;
    };

    class String : public IValue {
        public:
            String(std::string s) : m_val(s) {};

            std::string str() override {return m_val;};
        private:
            std::string m_val;
    };

    class Bool : public IValue {
        public:
            Bool(bool b) : m_val(b) {};
            bool get() {return m_val;};
            std::string str() override {return m_val ? "true" : "false";};
        private:
            bool m_val;
    };


} // end namespace

#endif