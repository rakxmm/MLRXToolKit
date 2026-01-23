#include "csv_value.hpp"
#include <sstream>

namespace rx::parser::csv {

    CSVObject::CSVObject(std::vector<IValue*> data)
    : m_data(std::move(data)) {};
    
    CSVObject::~CSVObject() {
        for (IValue* val : m_data) {
            delete val;
        }
    }

    std::string CSVObject::str() {
        std::stringstream ss;
        for (IValue* val : m_data) {
            ss << val->str();
        }
        return ss.str();
    }
    void CSVObject::add(IValue* val) {
        m_data.push_back(val);
    }


    


} // end namespace