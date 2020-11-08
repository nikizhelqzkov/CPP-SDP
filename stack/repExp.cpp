#include <string>
#include <stack>
#include <iostream>
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

bool isItLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
//3[ab]2[ac3[bg]]
//ababab acbgbgbg acbgbgbg

std::string makeExp(const std::string &exp)
{
    std::stack<int> num;
    std::stack<char> symbols;
    std::string res = "";
    std::string temp = "";
    bool level = false;
    int counter = 0;
    for (char s : exp)
    {
        if (isItNumber(s))
        {
            num.push(fromCharToInt(s));
        }
        else if (s == '[' || isItLetter(s))
        {
            if (s == '[')
            {
                counter++;
                if (counter > 1)
                {
                    level = true;
                }
            }
            symbols.push(s);
        }
        else if (s == ']')
        {
            if (counter >= 1 && level)
            {
                while (symbols.top() != '[' && !symbols.empty())
                {
                    temp.insert(temp.begin(), symbols.top());
                    symbols.pop();
                }
                symbols.pop();
                std::string t = temp;
                for (size_t i = 0; i < num.top() - 1; i++)
                {
                    temp += t;
                }
                t = "";
                counter--;
                if (counter == 0)
                {
                    level = false;
                    res += temp;
                }
                num.pop();
            }
            else if (counter == 1 && !level)
            {
                temp = "";
                while (symbols.top() != '[' && !symbols.empty())
                {
                    temp.insert(temp.begin(), symbols.top());
                    symbols.pop();
                }
                symbols.pop();
                if (!num.empty())
                {
                    for (size_t i = 0; i < num.top(); i++)
                    {
                        res += temp;
                    }
                    num.pop();
                    temp = "";
                }
                counter--;
            }
        }
    }
    // res = temp;
    return res;
}
int main()
{
    //abbgbg
    //chastichen uspeh
    std::string temp = "3[ab2[jg]3[vc]]3[gz]2[ds]";
    std::cout << makeExp(temp);
    // temp.insert(temp.begin(), 'f');
    // std::cout << temp << std::endl;
}