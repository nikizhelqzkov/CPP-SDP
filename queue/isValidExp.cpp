#include <queue>
#include <iostream>
#include <string>

bool isValidExp(const std::string &exp)
{
    std::queue<char> open;
    std::queue<char> close;
    for (char el : exp)
    {
        if (el == '(')
        {
            open.push(el);
        }
        else if (el == ')')
        {
            close.push(el);
        }
    }
    if (open.empty() && close.empty())
    {
        return true;
    }
    while (!open.empty() && !close.empty())
    {
        open.pop();
        close.pop();
    }
    return open.empty() && close.empty();
}

int main()
{
    std::cout<<isValidExp("((5+(3-3)*9)-50)*20");
    return 0;
}