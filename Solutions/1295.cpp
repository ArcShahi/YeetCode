
// 1295. Find Numbers with Even Number of Digits
#include <vector>
#include <cmath>
#include <algorithm>


constexpr int digit_count(int num)
{
     int count = 0;
     while (num > 0) 
     {
          num /= 10;
          ++count;
     }
     return count;
}

class Solution
{
public:
     int findNumbers(std::vector<int>& nums)
     {
         
          return std::count_if(begin(nums), end(nums), [](int x) 
               {return digit_count(x) % 2 == 0; });
     }
};