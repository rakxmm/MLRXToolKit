#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include <cassert>
#include <cctype>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#include "json_value.hpp"


#define NOT_IMPLEMENTED "NOT IMPLEMENTED"
#define INVALID_FORMAT "Invalid JSON format!"

#include <cstddef>
namespace rx {


// =========================================

class JSONParser {

public:
    JSONParser(std::string* text, size_t index) : m_text(text), m_index(index), m_root(nullptr), m_current(nullptr) {};

    JSONParser() : m_text(nullptr), m_index(0), m_root(nullptr), m_current(nullptr) {};

    void parse(const std::string* text) {
        m_index = 0;
        m_text = text;

        if (!m_text) throw std::runtime_error("[ERROR] Nullptr was passed to parse!");

        consumeWhiteSpace();
        char c = getCurrentChar();
        m_index++;
        switch (c) {
            case '[':
                m_root = parseArray();
                break;
            case '{':
                m_root = parseObject(nullptr);
                break;
            

        }
    };

    void consumeWhiteSpace() {
        while(std::isspace(getCurrentChar())) {
            m_index++;
            if (m_index >= m_text->size()) break;
        }
    };


    JSONValue* parseObject(JSONValue* parent) {
        consumeWhiteSpace();
        JSONNode* node = new JSONNode(parent);
        m_current = node;
        bool hasNext = true;
        while(hasNext) {
            char c = getCurrentChar();
            if (c == '}') {
                break;
            }
            node->push(parseJSONPair());
            
            consumeWhiteSpace();
            c = getCurrentChar();
            if(c == ',') {
                m_index++;
            }
        }
        m_index++;
        return node;
    }

    JSONValue* parseArray() {
        auto res = new JSONValue_array();
        m_current = res;
        bool hasNext = true;
        consumeWhiteSpace();
        char c = getCurrentChar();
        while(hasNext) {
            switch (c) {
                case ']':
                    hasNext = false;
                    break;
                case '{':
                    m_index++;
                    res->push(parseObject(m_current));
                    break;
                default:
                    res->push(parseValue());
                    break; 
            }
            consumeWhiteSpace();
            if (getCurrentChar() == ',') m_index++;
            consumeWhiteSpace();
            c = getCurrentChar();
        }    
        m_index++;
        // TODO: not fully implemented
        return res;
    }

    JSONPair* parseJSONPair() {
        consumeWhiteSpace();
        char c = getCurrentChar();
        if (c == '"') {
            m_index++;
        } else {
            throw std::runtime_error(INVALID_FORMAT);
        }
        std::string key = parseString();

        consumeWhiteSpace();
        JSONValue* value;
        if(getCurrentChar() == ':') {
            m_index++;
            consumeWhiteSpace();
            value = parseValue();
        } else {
            throw std::runtime_error(INVALID_FORMAT);
        }
        

        return new JSONPair(key, value);
    };

    std::string parseString() {
        std::string res = "";
        char c = getCurrentChar();
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
        std::string res = "";
        bool isFloat = false;
        char c = getCurrentChar();
        bool canRead = true;
        while(canRead) {
            res += c;
            if (c == '.') {
                if (isFloat) {
                    // Double floating point.
                    throw std::runtime_error(INVALID_FORMAT);
                }
                isFloat = true;
            }

            m_index++;
            c = getCurrentChar();
            if (c == ',' || c == ' ') canRead = false;
        }


        return std::stold(res.c_str(), NULL);
    }


    JSONValue* parseValue() {
        consumeWhiteSpace();
        char c = getCurrentChar();
        m_index++;
        switch (c) {
            case '"':
                return new JSONValue_string(parseString());
                break;
            case '[':
                return parseArray();
                break;
            case 'n':
                throw std::runtime_error(NOT_IMPLEMENTED);
                // return json null value
                break;
            case '{':
                return parseObject(m_current);
                break;
            default:
                if(std::isdigit(c)) {
                    c= getCurrentChar();
                    m_index--;
                    double long d = parseNumber();
                    std::string s = std::to_string(d);
                    m_index++;
                    return new JSONValue_num(d, s);
                }
                throw std::runtime_error(INVALID_FORMAT);
        }
    }

    ~JSONParser() {
        delete m_root;
    }

    JSONValue* getRoot() { return m_root; }
private:

    char getCurrentChar() {
        return (*m_text)[m_index];
    };

    const std::string* m_text; // text to be parsed
    size_t m_index; // current index in string
    JSONValue* m_root; // array or node
    JSONValue* m_current; // current node
};




} // end namespace

#endif