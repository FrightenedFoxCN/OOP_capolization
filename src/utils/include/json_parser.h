#ifndef _JSON_PARSER_H_
#define _JSON_PARSER_H_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

namespace Json {

template <class T>
class Reader {
    std::ifstream is;
public:
    Reader() = delete;
    Reader(const std::string &filename);
    virtual bool parse(std::map<std::string, T> &res) = 0;
    virtual ~Reader();
};

} // namespace Json

#endif