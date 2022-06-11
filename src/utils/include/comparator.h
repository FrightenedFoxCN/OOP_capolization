#include <cmath>

bool compareEqual(double x, double y)
{
    return abs(x - y) < 0.0001;
}

bool compareNotEqual(double x, double y)
{
    return !compareEqual(x, y);
}

bool compareGreaterThan(double x, double y)
{
    if (compareEqual(x, y))
        return false;
    return x > y;
}

bool compareGreaterorEqual(double x, double y)
{
    if (compareEqual(x, y))
        return true;
    return x >= y;
}

bool compareLessThan(double x, double y)
{
    if (compareEqual(x, y))
        return false;
    return x < y;
}

bool compareLessorEqual(double x, double y)
{
    if (compareEqual(x, y))
        return true;
    return x <= y;
}