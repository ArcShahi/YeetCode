// 2197. Replace Non-Coprime Numbers in Array

#include <vector>
#include <numeric>

// TIME COMPELXITY : O(nlogm)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {

          std::vector<int> stk{};

          for (auto& i : nums)
          {
               // Keep processing until top of stack and current num are NOT co-prime
               while (!stk.empty() && std::gcd(stk.back(),i)>1)
               {
                    i = std::lcm(stk.back(), i);
                    stk.pop_back();
               }
               stk.push_back(i);
          }
          return stk;
     }
};
 
// SIMILAR QUESTION 735