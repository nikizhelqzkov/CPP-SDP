#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include "operations.h"
bool isItNumber(char c)
{
    return c >= '0' && c <= '9';
}

int fromCharToInt(char c)
{
    if (!isItNumber(c))
    {
        throw "Not a number";
    }
    return (int)c - '0';
}
int result(std::string symbols)
{

    std::stack<int> results;
    int res = 0;
    int count = 0;
    while (count <= symbols.size())
    {
        if (isItNumber((symbols[count])))
        {
            results.push(fromCharToInt(symbols[count]));
            count++;
        }
        else
        {
            while (!results.empty())
            {
                res = Operations::Operate(symbols[count], results.top(), res);
                results.pop();
            }
            count++;
        }
    }
    return res;
}
int main()
{
    std::string symbols = {'3', '4', '8', '+', '7', '+', '2', '*'};

    std::cout << result(symbols);
}
