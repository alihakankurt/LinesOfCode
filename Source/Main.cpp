#include <Counter.hpp>
#include <iostream>

int main(int argc, const char* argv[])
{
    loc::Result result = loc::Counter::Count(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
