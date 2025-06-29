// 47. Permutations II
#include <vector>
#include <algorithm>



class Solution {
public:
     std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {

          std::vector<std::vector<int>> p{};
          std::ranges::sort(nums);

          do
          {
               p.push_back(nums);
          } while (std::next_permutation(begin(nums), end(nums)));

          return p;
     }
};