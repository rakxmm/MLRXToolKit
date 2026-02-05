#pragma once
#include <fstream>
#include <parser/parsed_data.hpp>
#include <filesystem>
#include <regex>
#include <windows.h>


namespace rx::parser {
    class Parser {
        public:
            virtual ~Parser() {closeFile();};

            virtual void parse(std::string filename) = 0;

            ParsedData getParsedData() {return m_parsedData;};
           
        protected:
            const std::string DEFAULT_COL_NAME = "col_";
            ParsedData m_parsedData;

            std::ifstream m_file;

            void openFile(const std::string& filename);
            
            void closeFile();

            long long parseInt(const std::string& token);
            
            bool parseBool(const std::string& token);

            long double parseFloat(const std::string& token);

            /** Returns Primitive DataType */
            DataType getType(const std::string& token) const;

            /** Returns Array DataType */
            DataType getArrayType(const std::string& token) const;

            /** Checks whether is token an array or not */
            bool isArray(const std::string& token) const;

            /** Removes all whitespaces and returns new trimmed object. */
            std::string trim(std::string token) const;

        private:
            // Regexes
            const std::regex intPattern{R"(^[-+]?[0-9]+$)"};
            const std::regex floatPattern{R"(^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$)"};
            const std::regex boolPattern{R"(^(true|false|yes|no)$)", std::regex_constants::icase};
            const std::regex quotePattern{R"(^".*"$)"};

            std::filesystem::path get_executable_path();
    
    };  


    
} // end rx::parser

