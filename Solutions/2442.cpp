// 2442. Count Number of Distinct Integers After Reverse Operations

#include <vector>
#include <unordered_set>

auto reverse_num(int x)
{
     auto num{ 0 };
     while (x)
     {
          num = (num * 10) + (x % 10);
          x /= 10;
     }
     return num;
}
// TIME COMPLEXITY : O(nlog(m)) where m is max value
// SPACE COMPLEXITY: O(n)
class Solution {
public:
     int countDistinctIntegers(std::vector<int>& nums) {

          std::unordered_set<int> set{};
          set.reserve(nums.size());

          for (const auto& i : nums)
          {
               set.insert(i);
               set.insert(reverse_num(i));
          }
       
          return set.size();
     }
};