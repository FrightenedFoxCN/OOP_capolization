#include "include/json_parser.h"

template <class T>
Json::Reader<T>::Reader(const std::string &filename){
    this->is.open(filename, std::ios::in);
}

