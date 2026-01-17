
#include "bitset.hpp"
#include "json_value.hpp"
#include "json_parser.hpp"
#include <cctype>
#include <chrono>
#include <cstddef>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>


#define LOG(x) std::cout << std::setprecision(10) << x << std::endl



double parseNumber(std::string& res) {
    // std::string res = parseString();
    return std::stold(res.c_str(), NULL);
}

int main() {
    std::ifstream file("../data/file.json");
    std::string text = "";
    std::string s;
    if(!file.is_open()) throw std::runtime_error("[ERROR] File was not found!");
    
    auto canRead = [&file, &s](){
        return !!std::getline(file, s); 
        return s.size() > 0;
    };

    while(canRead()) {
        text += s;
    }   
    
    LOG(text);
    

    // std::string a = "[{\"name\":\"Matthew\"}]";

    // std::string sd = "12321.723";

    rx::JSONParser parser(&text, 0);
    parser.parse(&text);
    // LOG(parser.parseRow().toString());
    

    


    file.close();

 
    return 0;
}