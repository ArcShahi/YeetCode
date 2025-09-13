// 128. Longest Consecutive Sequence

#include <vector>
#include <unordered_set>
#include <algorithm>

// TIME COMPELEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     int longestConsecutive(std::vector<int>& nums) {

          std::unordered_set<int> set{};
          set.reserve(nums.size());

          for (const auto& i : nums) set.insert(i);

          int longest{ 0 };
          for (const auto& n : set)
          {
               if (!set.count(n - 1))
               {
                    int length{ 1 };
                    while (set.count(n+length)>0)
                         ++length;
                    
                    longest = std::max(longest, length);
               }
               
          }
          return longest;
     }
};

// TIME COMPLEXITY : O(nLogn)
// SPACE COMPELXITY: O(1)

class Solution {
public:
     int longestConsecutive(std::vector<int>& nums) {

          if (nums.empty()) return 0;
          std::ranges::sort(nums);

          int longest{ 1 };
          int length{ 1 };

          for (int i{ 1 }; i < nums.size(); ++i)
          { 
               if (nums[i] - nums[i - 1] == 1) ++length;
               else if (nums[i] == nums[i - 1]) continue;
               else {
                    longest = std::max(longest, length);
                    length = 1;
               }
          }

          return std::max(longest, length);
     }
};