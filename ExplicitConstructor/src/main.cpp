#include <iostream>
#include "ExplicitObj.hpp"
#include "NonExplicitObj.hpp"

void foo(const ExplicitObj& obj)
{
    std::cout << obj;
}

void foo(const NonExplicitObj& obj)
{
    std::cout << obj;
}

void foo_withExplicit(const ExplicitObj& obj) 
{
    std::cout << obj;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    foo(5); // NonExplicitObj will be created

    // error: invalid initialization of reference of type ‘const ExplicitObj&’ from expression of type ‘int’
    // foo_withExplicit(10);

    ExplicitObj exObj(10);
    foo_withExplicit(exObj); // fine, ExplicitObj was created before

    return 0;
}