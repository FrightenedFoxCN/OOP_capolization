#ifndef _JSON_VALUE_H_
#define _JSON_VALUE_H_

#include <map>
#include <string>

namespace Json {

enum ValueType {
    nullValue = 0, // null value
    uintValue, // unsigned int value
    realValue, // double value
    stringValue, // UTF-8 string value
    boolValue, // boolean value 
    arrayValue, // array value
    pairwiseValue // name-value pairs
};

class Value {
    friend class ValueIterator;
    ValueType type;
    union ValueUnion{
        unsigned int uint_;
        double real_;
        std::string *string_;
        Value *array_;
        bool bool_;
        std::pair<std::string, Value> *pair_;
        ValueUnion(){};
        ~ValueUnion(){};
    } value;
public:
    Value(ValueType type = nullValue);
    Value(unsigned int uint_);
    Value(double real_);
    Value(char *string_);
    Value(std::string string_);
    Value(bool bool_);
    Value(std::pair<std::string, Value> *pair_);
    bool isNull(void);
    bool isUInt(void);
    bool isReal(void);
    bool isString(void);
    bool isArray(void);
    bool isBool(void);
    bool isPairwise(void);
};

} // namespace Json
#endif