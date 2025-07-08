// 1365. How Many Numbers Are Smaller Than the Current Number

#include <vector>
#include <algorithm>
#include <unordered_map>

// TIME COMPLEXITY : O(nlogn)

class Solution {
public:
     std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {

          std::vector<int> smaller{ nums };
          std::ranges::sort(smaller);
          std::unordered_map<int, int> hashmap{};

          for (int i{ 0 }; i < nums.size(); ++i)
               if (not hashmap.count(smaller[i]))
                    hashmap[smaller[i]] = i;
        
                 
          for (auto& x : nums)
               x = hashmap[x];

          return nums;

     }
};
