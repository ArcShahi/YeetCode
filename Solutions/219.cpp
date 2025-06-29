// 219. Contains Duplicate II

#include <vector>
#include <unordered_map>

class Solution {
public:
     bool containsNearbyDuplicate(std::vector<int>& nums, int k)
     {
          std::unordered_map<int, int> hash_map{};

          for (int i = 0; i < nums.size(); ++i) 
          {
               auto itr = hash_map.find(nums[i]);

               if (itr != hash_map.end() && abs(itr->second - i) <= k) 
               {
                    return true;
               }

               hash_map[nums[i]] = i;  // Update the index of the current element
          }

          return false;
     }
};
