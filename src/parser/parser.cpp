#include <fstream>
#include <parser/parser.hpp>
#include <stdexcept>


#define FILE_NOT_OPEN "Failed to open/find the file! "

namespace rx::parser {

    std::filesystem::path Parser::get_executable_path() {
        wchar_t path[MAX_PATH];
        GetModuleFileNameW(NULL, path, MAX_PATH);
        return std::filesystem::path(path).parent_path(); // Vráti priečinok, kde je .exe
    }

    void Parser::openFile(const std::string& filename) {
        std::filesystem::path exepath = get_executable_path();
        std::filesystem::path data_path = exepath.parent_path() / "data" / filename;

        m_file = std::ifstream(data_path);
        
        if(!m_file.is_open()) throw std::runtime_error(FILE_NOT_OPEN);
        // TODO
    };

    void Parser::closeFile() {
        if(m_file.is_open()) {
            m_file.close();
        }
    };


} // end rx::parser