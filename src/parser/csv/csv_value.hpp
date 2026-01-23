#pragma once

#include "../i_value.hpp"
#include <vector>

namespace rx::parser::csv {

    // Refers to one column in the csv file.
    class CSVObject : public IValue {
        public:
            CSVObject(std::vector<IValue*> data);

            std::string str() override;

            ~CSVObject();

            void add(IValue* val);
        private:
            CSVObject() {};
            std::vector<IValue*> m_data; // array of ivalues

    };



} // end namespace