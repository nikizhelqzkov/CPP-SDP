#include <iostream>

int test(int t)
{
    
    return t>=5 ? 30 : 25;
}

int main()
{
    std::cout << test(3) << std::endl;
    return 0;
}