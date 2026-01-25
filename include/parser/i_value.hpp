#pragma once
#include <string>

namespace rx::parser {
    class IValue {
        public:
            virtual std::string str() const = 0;
            virtual ~IValue() = default;
    };

    class IntVal : public IValue {
       public:
            IntVal(const long int* val) : m_val(val) {};

            std::string str() const override {
                return std::to_string(*m_val);
            };

        private:
            const long int* m_val; 
    };

    class FloatVal : public IValue {
        public:
            FloatVal(const long double* val) : m_val(val) {};

            std::string str() const override {
                return std::to_string(*m_val);
            };

        private:
            const long double* m_val;
    };


    class BoolVal : public IValue {
        public:
            BoolVal(bool* ptr) : m_ptr(ptr) {};

            std::string str() const override {
                return (*m_ptr) ? "true" : "false";
            };
        private:
            const bool* m_ptr;
    };


    class StringVal : public IValue {
        public:
            StringVal(std::string* ptr) : m_ptr(ptr) {};

            std::string str() const override {
                return *m_ptr;
            };
        
        private:
            const std::string* m_ptr;
    };



} // end rx::parser