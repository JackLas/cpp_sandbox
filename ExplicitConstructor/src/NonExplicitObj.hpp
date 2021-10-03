#ifndef __NON_EXPLICIT_OBJ_HPP__
#define __NON_EXPLICIT_OBJ_HPP__

#include "Obj.hpp"

class NonExplicitObj : public Obj
{
    using BaseClass = Obj;
public:
    NonExplicitObj(const int value) 
        : BaseClass(value)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const Obj& obj);

protected:
    const char* name() const override
    {
        return "NonExplicitObj";
    }
};

#endif // __NON_EXPLICIT_OBJ_HPP__