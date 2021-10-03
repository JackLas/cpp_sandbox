#ifndef __EXPLICIT_OBJ_HPP__
#define __EXPLICIT_OBJ_HPP__

#include "Obj.hpp"

class ExplicitObj : public Obj
{
    using BaseClass = Obj;
public:
    explicit ExplicitObj(const int value) 
        : BaseClass(value)
    {
    }

protected:
    const char* name() const override
    {
        return "ExplicitObj";
    }
};

#endif // __EXPLICIT_OBJ_HPP__