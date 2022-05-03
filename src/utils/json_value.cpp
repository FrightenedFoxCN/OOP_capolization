#include "include/json_value.h"

using namespace Json;

Value::Value(ValueType type /* = nullValue*/) {
    this->type = type;
}

Value::Value(unsigned int uint_) {
    this->type = uintValue;
    this->value.uint_ = uint_;
}

Value::Value(double real_) {
    this->type = realValue;
    this->value.real_ = real_;
}

Value::Value(char *string_) {
    this->type = stringValue;
    this->value.string_ = new std::string(string_);
}

Value::Value(std::string string_) {
    this->type = stringValue;
    this->value.string_ = new std::string(string_);
}

    // Value(bool bool_);
    // Value(std::pair<std::string, Value> *pair_);