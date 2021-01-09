#include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_map<int, char> m{{20, 'a'}, {25, 'w'}, {19, '1'}};
    for (auto &&[key, value] : m)
    {
        std::cout << key << "\n";
    }

    // auto f = m.find(895);
    // bool isOk = f != m.end();
    // std::cout << std::boolalpha << (m.count(20) == true) << " ; " << (m.count(89) == true) << " " << isOk<<"\n\n\n\n";
}