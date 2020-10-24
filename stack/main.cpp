#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include "operations.h"
bool isItNumber(char c)
{
    return c >= '0' && c <= '9';
}
std::string normalToRevPolNot(const std::string &exp)
{
    std::stack<char> s;
    std::string newS;
    for (char symbol : exp)
    {
        if (isItNumber(symbol))
        {
            newS.push_back(symbol);
        }
        else
        {
            s.push(symbol);
        }
        while (s.top() == ')' && s.top() != '(')
        {
            s.pop();
            newS.push_back(s.top());
            s.pop();
        }
    }
    return newS;
}
int fromCharToInt(char c)
{
    if (!isItNumber(c))
    {
        throw "Not a number";
    }
    return (int)c - '0';
}
double result(std::string symbols)
{

    std::stack<double> results;
    double res = 0;
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
    // std::string symbols = {'3', '4', '8', '+', '7', '+', '2', '*'};

    //std::cout << result(symbols);
    std::string r = "((((3+2)*3)-4)/2)";
    std::cout << r<<std::endl;
    r = normalToRevPolNot(r);
    std::cout << r<<std::endl;
    std::cout << result(r);
}
