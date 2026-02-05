#include "parser/parsed_data.hpp"
#include <cctype>
#include <cmath>
#include <fstream>
#include <parser/parser.hpp>
#include <regex>
#include <stdexcept>
#include <cassert>
#include <charconv>
#include <string>

#define FILE_NOT_OPEN "Failed to open/find the file! "

namespace rx::parser {

    std::filesystem::path Parser::get_executable_path() {
        wchar_t path[MAX_PATH];
        GetModuleFileNameW(NULL, path, MAX_PATH);
        return std::filesystem::path(path).parent_path(); // Vráti priečinok, kde je .exe
    }

    void Parser::openFile(const std::string& filename) {
        std::filesystem::path exepath = get_executable_path();
        std::filesystem::path data_path = exepath.parent_path() / "data" / filename;

        m_file = std::ifstream(data_path);
        
        if(!m_file.is_open()) throw std::runtime_error(FILE_NOT_OPEN);
        // TODO
    };

    void Parser::closeFile() {
        if(m_file.is_open()) {
            m_file.close();
        }
    };

    DataType Parser::getType(const std::string& token) const {
        if (std::regex_match(token, floatPattern)) return DataType::FLOAT;
        if (std::regex_match(token, intPattern)) return DataType::INT;
        if (std::regex_match(token, boolPattern)) return DataType::BOOL;
        return DataType::STRING;
    }

    DataType Parser::getArrayType(const std::string& token) const {
        std::string elems = token.substr(1, token.size() - 2); // removes opening and closing brackets []
        auto comma_index = elems.find(','); // find ','
        if (comma_index == std::string::npos) { // if there is no ','
            if (elems.empty()) return DataType::ARRAY_STRING; // default array type if empty array
            comma_index = elems.size();
        }

        // otherwise, substring the token and check the value type.
        elems = elems.substr(0, comma_index);
        elems = trim(elems); // remove all whitespaces
        if (std::regex_match(elems, floatPattern)) return DataType::ARRAY_FLOAT;
        if (std::regex_match(elems, intPattern)) return DataType::ARRAY_INT;
        if (std::regex_match(elems, boolPattern)) return DataType::ARRAY_BOOL;
        return DataType::ARRAY_STRING;
    }

    bool Parser::isArray(const std::string& token) const {
        if (token.size() < 2) return false;
        return (token.front() == '[' && token.back() == ']');
    };
   
    std::string Parser::trim(std::string token) const {
        std::string result = "";
        for (char c : token) {
            if (!std::isspace(c)) {
                result += c;
            }
        }
        return result;
    }
} // end rx::parser