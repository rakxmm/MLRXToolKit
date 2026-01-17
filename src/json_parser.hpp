#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include <cassert>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#include "json_value.hpp"
#define _VAL JSONValue*

#define NOT_IMPLEMENTED "NOT IMPLEMENTED"


#include <cstddef>
namespace rx {


// =========================================

class JSONParser {

public:
    JSONParser(std::string* text, size_t index) : m_text(text), m_index(index) {};

    JSONParser() : m_index(0) {};

    void parse(const std::string* text) {
        m_index = 0;
        m_text = text;

        if (!m_text) throw std::runtime_error("[ERROR] Nullptr was passed to parse!");

        consumeWhiteSpace();
        char c = (*m_text)[m_index];
        switch (c) {
            case '[':
                m_root = parseJSONArray();
                break;
            case '{':
                m_root = parseJSONObject();
                break;
            

        }
    };

    void consumeWhiteSpace() {
        char c = (*m_text)[m_index];
        while(std::isspace(c)) {
            c = (*m_text)[m_index];
            m_index++;
            if (m_index >= m_text->size()) break;
        }
    };


    _VAL parseJSONObject() {
        throw std::runtime_error(NOT_IMPLEMENTED);
        return nullptr;
    }

    _VAL parseJSONArray() {
        _VAL res = new JSONValue_array();

        throw std::runtime_error(NOT_IMPLEMENTED);
        return nullptr;
    }

    JSONPair parseJSONPair() {
        consumeWhiteSpace();
        char c = (*m_text)[m_index];

        if (c == '"') {
            m_index++;
        } else {
            throw std::runtime_error("[ERROR] Should be \" an is not!");
        }
        std::string key = parseString();

        consumeWhiteSpace();
        c = (*m_text)[m_index];
        _VAL value;
        if(c == ':') {
            m_index++;
            consumeWhiteSpace();
            value = parseValue();
        } else {
            throw std::runtime_error("[ERROR] Invalid json format!");
        }
        

        return JSONPair(key, value);
    };

    std::string parseString() {
        std::string res = "";
        char c = (*m_text)[m_index];
        while(c != '"') {
            res += c;
            m_index++;
            if (m_index>= m_text->size()) return res;
            c = (*m_text)[m_index];
        }
        m_index++;
        return res;
    }

    double parseNumber() {
        std::string res = parseString();
        return std::stold(res.c_str(), NULL);
    }


    _VAL parseValue() {
        char c = (*m_text)[m_index];
        m_index++;
        switch (c) {
            case '"':
                return new JSONValue_string(parseString());
                break;
            case '[':
                throw std::runtime_error(NOT_IMPLEMENTED);
                return new JSONValue_array(); 
                break;
            default:
                double long d = parseNumber();
                std::string s = std::to_string(d);
                return new JSONValue_num(d, s);
                break;
        }
        
        throw std::runtime_error(NOT_IMPLEMENTED);
        return nullptr;
    }

    ~JSONParser() {}

private:
    const std::string* m_text; // text to be parsed
    size_t m_index; // current index in string
    _VAL m_root;
};




} // end namespace

#endif