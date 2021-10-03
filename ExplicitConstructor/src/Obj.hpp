#ifndef __OBJ_HPP__
#define __OBJ_HPP__

#include <iostream>

class Obj 
{
public:
    Obj(const int value) 
        : m_value(value)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const Obj& obj);

protected:
    virtual const char* name() const = 0;

private:
    int m_value;
};

std::ostream& operator<<(std::ostream& os, const Obj& obj)
{
    os << obj.name() << ": " << obj.m_value << "\n";
    return os;
}

#endif // __OBJ_HPP__