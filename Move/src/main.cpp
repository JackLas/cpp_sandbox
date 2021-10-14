#include <iostream>
#include "Obj.hpp"

void run(void(*func)(), const char* msg = "\0") 
{
    std::cout << msg << std::endl;
    func();
    std::cout << "----------------------------------------\n\n";
}

void test0()
{
    int one = 1;
    int two = 2;

    one = std::move(2);
    std::cout << "one = " << one << ", two = " << two << std::endl;
    // one = 2, two = 2

    std::cout << ">>> set two = 3\n";
    two = 3;
    std::cout << "one = " << one << ", two = " << two << std::endl;
    // one = 2, two = 3

    // base types doesn't have "move ctor", so they're just copied

    std::cout << "~~~~\n";
}

void test1()
{
    Obj first(1);
    Obj second(2);
    first = std::move(second);

    std::cout << "first = " << first.value() << ", second = " << second.value() << std::endl;
    // first = 2, second = 2

    std::cout << "address first = " << &first << ", address second = " << &second << std::endl;
    // the addresses are different

    //the move-is-a-copy paradigm applies to all data structures composed of POD types

    std::cout << "~~~~\n";
}

#include <vector>
void test2()
{
    std::vector<Obj> base{Obj(1), Obj(2), Obj(3), Obj(4)};

    std::cout << "base vector size = " << base.size() << std::endl;
    // base vector size = 4

    std::cout << ">>> move \"base\" to \"moved\" vector" << std::endl;
    std::vector<Obj> moved = std::move(base);
    std::cout << "base vector size = " << base.size() << std::endl;
    std::cout << "moved vector size = " << moved.size() << std::endl;
    // base vector size = 0
    // moved vector size = 4

    // vector's values were moved without copying

    std::cout << "~~~~\n";
}

void test3()
{
    // not compilable
    // std::vector<Obj> base{std::move(Obj(0)), std::move(Obj(1)), std::move(Obj(2)), std::move(Obj(3))};

    // not compilable, since ctor is explicit
    // std::vector<Obj> vec{111, 222, 333, 444};

    std::cout << "--------------------------\n";
    std::cout << "check emplace_back(Obj(1))\n";

    std::vector<Obj> named;
    named.reserve(4);
    named.emplace_back(Obj(1)); // tmp obj created and move ctor called
    named.emplace_back(Obj(2)); // tmp obj created and move ctor called
    named.emplace_back(Obj(3)); // tmp obj created and move ctor called
    named.emplace_back(Obj(4)); // tmp obj created and move ctor called

    std::cout << "--------------------------\n";
    std::cout << "check emplace_back(11)\n";

    std::vector<Obj> base;
    base.reserve(4);
    base.emplace_back(11); // built inside vector, no tmp objects
    base.emplace_back(22); // built inside vector, no tmp objects
    base.emplace_back(33); // built inside vector, no tmp objects
    base.emplace_back(44); // built inside vector, no tmp objects

    std::cout << "~~~~\n";
}

void test4_rval_set(Obj&& o)
{
    //Obj test(o); // copy ctor called
    Obj test(0);
    test = o; // copy assing called
    std::cout << test.value() << "\n";
}

void test4_rval_move(Obj&& o)
{
    Obj test(std::move(o)); // move ctor called
    std::cout << test.value() << "\n";
}

void test4()
{
    Obj test11(11);
    // notcompilable, since parameter is rvalue reference (Obj&&)
    // test4_rval_set(test11);

    //only std::move(test11) is available
    test4_rval_set(std::move(test11)); // copy will be called inside
    std::cout << std::endl;

    Obj test22(22);
    test4_rval_move(std::move(test22)); // move ctor will be called inside

    std::cout << "~~~~\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    run(test0, "test0");
    run(test1, "test1");
    run(test2, "test2");
    run(test3, "test3");
    run(test4, "test4");

    return 0;
}