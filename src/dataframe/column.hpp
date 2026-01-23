#ifndef COLUMN_HPP
#define COLUMN_HPP


#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
namespace df {  
    /**
        Interface IColumn
    */
    class IColumn {
        public:
            IColumn(std::string name) : m_Name(name) {};

            virtual ~IColumn() = 0;

            // Returns number of elements stored in the column.
            virtual size_t size() = 0;

            // Returns name of the column.
            std::string name() {return m_Name;};

            virtual std::string toString() = 0;

            virtual std::string at(size_t index) = 0;

        private:
            std::string m_Name;

    };

    inline IColumn::~IColumn() {};

    template<typename T>
    class Column : public IColumn {        
        public:
            Column(std::string name, std::vector<T> data);

            const std::vector<T> values();

            const T operator[](size_t index);

            std::string at(size_t index) override;

            size_t size() override {return m_Data.size();}

            std::string toString() override;

        private:
            std::vector<T> m_Data;
    };

    template<typename T>
    Column<T>::Column(std::string name, std::vector<T> data) : IColumn(name), m_Data(data) {};

    template<typename T>
    const std::vector<T> Column<T>::values() {
        return m_Data;
    }

    template<typename T>
    const T Column<T>::operator[](size_t index) {
        if (index >= m_Data.size()) throw std::out_of_range("Out of range in 'operator[]'!");
        return m_Data.at(index);
    }

    template<typename T>
    std::string Column<T>::toString() {
        std::string s = '\t' + name() + '\n';
        int i = 0;
        for (T t : m_Data) {
            (void)t;
            std::stringstream ss;
            ss << t;
            s += std::to_string(i);



            s += '\t'+ ss.str() + '\n';
            
            i++;
        }
        return s;
    };

    template<typename T>
    std::string Column<T>::at(size_t index) {
        if (index >= m_Data.size()) throw std::out_of_range("Out of range in 'at()' function!");
        std::stringstream ss;
        ss << m_Data.at(index);
        return ss.str();
    }


} // end namespace 



#endif