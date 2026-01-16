#include "bitset.hpp"
#include <iostream>



namespace ds {

    Bitset32::Bitset32() : m_bits(0) {};

    void Bitset32::setBit(int index) {
        std::uint32_t temp = 1;
        for(int i = 0; i < index; i++) {
            temp = temp << 1;
            std::cout << temp << std::endl;
        }
        m_bits = m_bits | temp;
    };

    void Bitset32::resetBit(int index) {
        std::uint32_t temp = 1;
        for(int i = 0; i < index; i++) {
            temp = temp << 1;
        }
        m_bits = m_bits & ~temp;
    }

    bool Bitset32::getBit(int index) {
        std::uint32_t temp = 1;
        for(int i = 0; i < index; i++) {
            temp = temp << 1;
        }
        return m_bits & temp;
    }

    void Bitset32::print() {
        for(int i = 32; i > 0; i--) {
            if(getBit(i)) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    };

} // endnamespace ds