#include "csv_parser.hpp"
#include "csv_value.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace rx::parser::csv {

    std::vector<IValue*> parseHeader(std::string& header) {
        std::vector<IValue*> output;
        (void)header;
        // TODO
        return output;
    }; 

    IValue* CSVParser::parse(const std::string& filepath) {
        CSVObject* root = nullptr;

        // Verification if file has right extension/suffix.
        std::string suffix = std::filesystem::path(filepath).extension().string();
        if (suffix != ".csv") throw std::runtime_error("[ERROR] File format is not correct!");

        // Tries to open the file.
        std::ifstream file(filepath);

        if(!file.is_open()) throw std::runtime_error("[ERROR] File was not found!");
        
        std::string line;

        // Checks if is possible to continue.
        auto canRead = [&file, &line](){
            return !!std::getline(file, line);
        };  


        // We need to check and compare first two lines, if there's a header!
        CSVObject* first = nullptr;
        CSVObject* second = nullptr;

        for (size_t i = 0; i < 2; i++) {
            if (canRead()) {
                parseLine(line);
            }
        }


        while(canRead()) {
            // 
        }

        file.close();
        return root;
    };

    std::vector<IValue*> CSVParser::parseLine(std::string& line) {
        std::vector<IValue*> result;

        auto resetStringStream = [](std::stringstream& ss){
            ss.str("");
            ss.clear();
        };

        std::stringstream ss;

        bool quotes = false;
        for (char c : line) {
            if (c == '\"') {
                quotes = !quotes;
            }

            if (!quotes && (c == ',' || c == line.back())) {
                if (c != ',') ss << c;
                std::string word = ss.str();
                if (word.size() > 0) {
                    IValue* e = Parser::parseWord(word);
                    result.push_back(e);
                    resetStringStream(ss);
                } 

            } else {
                if (c != '\"') ss << c; // To avoid starting or ending quotes in the string for better parsing.
            }
        }
        
        return result;
    }


    

} // end namespace