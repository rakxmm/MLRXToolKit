#pragma once
#include <fstream>
#include <parser/parsed_data.hpp>
#include <filesystem>
#include <windows.h>

<<<<<<< Updated upstream

namespace rx::parser {

=======
namespace rx::parser {
    class Parser {
        public:
            virtual ~Parser() {closeFile();};

            virtual void parse(std::string filename) = 0;

            ParsedData getParsedData() {return m_parsedData;};
        protected:
            ParsedData m_parsedData;

            std::ifstream m_file;

            void openFile(const std::string& filename);
            
            void closeFile();

        private:
            std::filesystem::path get_executable_path();
    };  
>>>>>>> Stashed changes
    
} // end rx::parser

