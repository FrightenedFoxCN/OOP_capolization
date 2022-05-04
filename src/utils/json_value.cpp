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

Value::Value(bool bool_)
{
    this->type = boolValue;
    this->value.bool_ = bool_;
}

Value::Value(std::pair<std::string, Value> *pair_)
{
    this->type = pairwiseValue;
    this->value.pair_ = pair_;
}

bool Value::isNull(void)
{
    return this->type == nullValue;
}

bool Value::isUInt(void)
{
    return this->type == uintValue;
}

bool Value::isReal(void)
{
    return this->type == realValue;
}

bool Value::isString(void)
{
    return this->type == stringValue;
}

bool Value::isArray(void)
{
    return this->type == arrayValue;
}

bool Value::isBool(void)
{
    return this->type == boolValue;
}

bool Value::isPairwise(void)
{
    return this->type == pairwiseValue;
}