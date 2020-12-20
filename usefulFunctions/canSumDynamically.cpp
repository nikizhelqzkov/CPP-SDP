#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <time.h>

std::map<int, bool> memo;
bool canSum(int targetSum, std::vector<int> numbers)
{
    if (memo.find(targetSum) != memo.end())
    {
        return memo[targetSum];
    }
    if (targetSum == 0)
    {
        return true;
    }
    if (targetSum < 0)
    {
        return false;
    }
    for (auto &&num : numbers)
    {
        const int remainder = targetSum - num;
        if (canSum(remainder, numbers))
        {
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}

int main()
{
    std::cout << canSum(7, {2, 3}) << std::endl;
    memo.clear();
    std::cout << canSum(7, {5, 3, 4, 7}) << std::endl;
    memo.clear();
    std::cout << canSum(8, {2, 3, 5}) << std::endl;
    memo.clear();
    std::cout << canSum(7, {2, 4}) << std::endl;
    memo.clear();
    std::cout << canSum(300, {7, 14}) << std::endl;
}