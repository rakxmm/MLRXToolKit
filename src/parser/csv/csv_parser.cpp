#include "csv_parser.hpp"
#include "csv_value.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace rx::parser::csv {

    std::vector<IValue*> parseHeader(std::string& header) {
        std::vector<IValue*> output;
        // TODO
        return output;
    }; 

    IValue* CSVParser::parse(const std::string& filepath) {
        CSVObject* root = nullptr;
        std::cout << "Aktualny adresar: " << std::filesystem::current_path() << std::endl;
        std::string suffix = std::filesystem::path(filepath).extension().string();
        if (suffix != ".csv") throw std::runtime_error("[ERROR] File format is not correct!");

        std::ifstream file(filepath);

        if(!file.is_open()) throw std::runtime_error("[ERROR] File was not found!");
        
        std::string line;

        // Checks if is possible to continue.
        auto canRead = [&file, &line](){
            return !!std::getline(file, line);
        };  

        size_t i = 0;
        while(canRead()) {
            if (i < 5) {
                std::cout << line;
                i++;
            } else {
                break;
            }
        }

        file.close();
        return root;
    };


} // end namespace