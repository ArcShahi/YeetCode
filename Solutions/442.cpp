//442. Find All Duplicates in an Array
#include <vector>
#include <unordered_map>

// Time: O(n)
// Space: O(1) auxiliary(excluding output)


class Solution {
public:
     std::vector<int> findDuplicates(std::vector<int>& nums) {

          std::vector<int> duplicates{};
          for (int i{ 0 }; i < nums.size(); ++i)
          {
               int val{ std::abs(nums[i]) };
               int idx{ val - 1 };

               if (nums[idx] > 0)
                    nums[idx] = -nums[idx];
               else
                    duplicates.push_back(val);
          }
          return duplicates;
     }
};