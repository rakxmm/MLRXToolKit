#include <dataframe/basecol.hpp>
#include <dataframe/datacol.hpp>
#include <parser/parsed_data.hpp>
#include <parser/parser.hpp>
#include <iostream>
#include <parser/csv/csvparser.hpp>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#define NOT_IMPLEMENTED "TODO: Not implemented yet"

namespace rx::parser::csv {
    
    void CSVParser::parse(std::string filename) {
        
        std::regex csvPattern("\\.[cC][sS][vV]$"); // checks if such file is .csv format
        if (!std::regex_search(filename, csvPattern)) throw std::runtime_error("Wrong file extension/suffix.");
        
        std::string line; // one line in the file;
        Parser::openFile(filename); // opens file into the m_file

        auto canRead = [this](std::string& line){
            return !!std::getline(m_file, line);
        };

        std::vector<std::string> tokens; 
        std::vector<std::string> col_names;
        if (canRead(line)) {
            tokens = getTokens(line);
            if (m_hasHeader) {
                // if header exists, then tokens are currently names of the columns
                col_names = std::move(tokens);
                tokens = (canRead(line)) ? 
                    getTokens(line) : 
                        throw std::runtime_error("Cannot determine what datacols shoud be created!");
            } else {
                 // set default names for the columns
                for (size_t index = 0; index < tokens.size(); index++) {
                    col_names.push_back(DEFAULT_COL_NAME + std::to_string(index));
                }
            }

            // get datatypes for cols
            std::vector<DataType> col_datatypes = getTokensTypes(tokens);
           
            for (size_t index = 0; index < tokens.size(); index++) {
                DataType datatype = col_datatypes.at(index);
                df::BaseCol* col = nullptr;
                switch (datatype) {
                    case DataType::INT:
                        col = new df::DataCol<long int>();                            
                        break;
                    case DataType::FLOAT:
                        col = new df::DataCol<long double>(); 
                        break;
                    case DataType::BOOL:
                        col = new df::DataCol<bool>(); 
                        break;
                    case DataType::STRING:
                        col = new df::DataCol<std::string>(); 
                        break;
                    case DataType::ARRAY_BOOL:
                        throw std::runtime_error(NOT_IMPLEMENTED);
                        break;
                    case DataType::ARRAY_INT:
                        throw std::runtime_error(NOT_IMPLEMENTED);
                        break;
                    case DataType::ARRAY_FLOAT:
                        throw std::runtime_error(NOT_IMPLEMENTED);
                        break;
                    case DataType::ARRAY_STRING:
                        throw std::runtime_error(NOT_IMPLEMENTED);
                        break;
                    default:
                        throw std::runtime_error("Unknown DataType error.");
                        break;
                }
                col->push(tokens.at(index));
                m_parsedData.addColumn(col, col_names.at(index));
            }
            
        } else {
            throw std::runtime_error("Cannot read first line of the specified file.");
        }

        while(canRead(line)) {
            tokens = getTokens(line);
            for (size_t i = 0; i < m_parsedData.colCount(); i++) {
                std::string token = (i < tokens.size()) ? tokens.at(i) : "";
                m_parsedData[i]->push(token);
            }
        }
    };

    /** Parses line into the vector of tokens separated by specified separator. */
    std::vector<std::string> CSVParser::getTokens(std::string& line) {
        std::vector<std::string> tokens;

        std::string token;
        token.reserve(30); // for optimization
        bool hasQuotes = false;
    
        for (char c : line) {
            if (c == '"') {
                hasQuotes = !hasQuotes;
            } else if (c == m_separator && !hasQuotes) {
                tokens.push_back(token);
                token.clear();
            } else {
                token+=c;
            }
        };
        tokens.push_back(token);
        return tokens;
    };

    std::vector<rx::parser::DataType> CSVParser::getTokensTypes(const std::vector<std::string>& tokens) const {
        std::vector<DataType> datatypes;
        datatypes.reserve(tokens.size());

        for (const std::string& token : tokens) {
            if (token.empty()) {
                // default case if empty token => string
                datatypes.push_back(DataType::STRING);
            } else {
                if (isArray(token)) {
                    datatypes.push_back(getArrayType(token));
                } else {
                    datatypes.push_back(getType(token));
                }
            }
        }
        return datatypes;
    };


} // end rx::parser::csv