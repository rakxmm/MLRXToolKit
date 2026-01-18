
#include "json_value.hpp"
#include "json_parser.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>


#define LOG(x) std::cout << std::setprecision(3) << x << std::endl

int main (int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    std::ifstream file(argv[1]);
    // std::ifstream file("../data/file.json");
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
    
    rx::JSONParser parser;
    parser.parse(&text);
    LOG(parser.getRoot()->toString());


    file.close();

 
    return 0;
}