#ifndef BITSET_HPP
#define BITSET_HPP


#include <cstdint>
namespace ds {

class Bitset32 {
public:
    Bitset32();
    void setBit(int index);
    void resetBit(int index);
    bool getBit(int index);
    void print();
private:
    std::uint32_t m_bits;

};


} // end namespace



#endif