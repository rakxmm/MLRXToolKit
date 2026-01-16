
#include "bitset.hpp"
#include <cstring>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#define LOG(x) std::cout << x << std::endl





class String {
    char* m_string;   
    std::size_t m_size;

public:
    String(const char* str) : m_size(strlen(str) ) {
        m_string = new char[m_size + 1];
        memcpy(m_string, str, m_size);
        m_string[m_size] = 0;
    };

    ~String() {
        delete[] m_string;
    }

    friend std::ostream& operator<<(std::ostream& ost, String& s);
    
    int getSize() const {
        return m_size;
    }

};

std::ostream& operator<<(std::ostream& ost, String& s) {
        ost << s.m_string;
        return ost;
};

#include <fstream>

int main() {
    std::ifstream file("../data/file.json");
    std::string s;
    if(!file.is_open()) throw std::runtime_error("[ERROR] File was not found!");
    
    auto canRead = [&file, &s](){
        return !!std::getline(file, s); 
        // return s.size() > 0;
    };

    while(canRead()) {
        LOG(s);
    }   
    
    file.close();
    return 0;
}