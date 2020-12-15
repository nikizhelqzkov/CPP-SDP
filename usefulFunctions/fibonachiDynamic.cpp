// C++ program for building suffix array of a given text
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <time.h>
bool is_number(const std::string &s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
// Driver program to test above functions

long long unsigned int fib(int n)
{
    static std::map<int, int> memory;
    if (memory.find(n) != memory.end())
    {
        return memory[n];
    }
    if (n <= 2)
    {
        return 1;
    }
    memory[n] = fib(n - 2) + fib(n - 1);
    return memory[n];
}

long long unsigned int fibonacci(int n)
{
    static std::map<int, int> values;
    if (n <= 2)
        return 1;
    std::map<int, int>::iterator iter = values.find(n);
    if (iter != values.end())
    {
        return iter->second;
    }

    return values[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
long long unsigned int fib2(int n)
{
    if (n <= 2)
        return 1;
    return fib2(n - 1) + fib2(n - 2);
}
int main()
{

    // std::map<int, std::vector<std::string>> m;
    // m.insert({5, {"Hello", "workd"}});
    // m[5].push_back("gr");
    // std::cout << m[5][2] << std::endl;
    // std::cout << is_number("651365312") << is_number("987465 484");
    //std::map<std::string, int> f;
    clock_t tStart = clock();
    std::cout << fibonacci(40) << " memory:" << (double)(clock() - tStart) / CLOCKS_PER_SEC << std::endl;
    std::cout << fib(40) << " memory:" << (double)(clock() - tStart) / CLOCKS_PER_SEC << std::endl;
    std::cout << fib2(40) << " memory:" << (double)(clock() - tStart) / CLOCKS_PER_SEC << std::endl;
    return 0;
}