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

int main()
{
    std::map<int, std::vector<std::string>> m;
    m.insert({5, {"Hello", "workd"}});
    m[5].push_back("gr");
    std::cout << m[5][2] << std::endl;
    std::cout << is_number("651365312") << is_number("987465 484");
    std::map<std::string, int> f;
}