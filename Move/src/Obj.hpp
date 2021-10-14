#ifndef __OBJ_HPP__
#define __OBJ_HPP__

#include <iostream>

#define CHECK std::cout << __PRETTY_FUNCTION__ << "(" << m_value << ")" << std::endl

class Obj 
{
public:
    explicit Obj(const int value) 
        : m_value(value)
    {
        CHECK;
    }

    explicit Obj(const Obj& other)
    {
        CHECK;
        m_value = other.m_value;
    }

    explicit Obj(Obj& other)
    {
        CHECK;
        m_value = other.m_value;
    }

    explicit Obj(Obj&& other)
    {
        CHECK;
        m_value = std::move(other.m_value);
    }

    Obj& operator=(Obj&& other) 
    {
        CHECK;
        m_value = std::move(other.m_value);

        return *this;
    }

    Obj& operator=(const Obj& other) 
    {
        CHECK;
        m_value = other.m_value;

        return *this;
    }

    ~Obj() 
    {
        CHECK;
    }

    int value() const
    {
        return m_value;
    }

private:
    int m_value = -1; 
};

#endif // __OBJ_HPP__