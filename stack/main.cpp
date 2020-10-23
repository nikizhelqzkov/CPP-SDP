#include <iostream>
#include <stack>
#include <string>
#include <exception>
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
int cPlus(char c, int n, int prev)
{
    if (c != '+')
    {
        throw "error operator";
    }
    return prev + n;
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
            //metoda koito da znae kakva e operaciqta. raboti s plus
            while (!results.empty())
            {
                res = cPlus(symbols[count], results.top(), res);
                results.pop();
            }
            count++;
        }
    }
    return res;
}
int main()
{
    std::string symbols = {'3', '4','8', '+', '7', '+', '2', '+'};

    //std::cout << fromCharToInt('3');
    std::cout << result(symbols);
}

//da suzdam funkciq ot po visok red koqto da vrushta funkciq koqto da smqta razlichnite operacii