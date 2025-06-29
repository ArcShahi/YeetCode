// 31. Next Permutation


#include <iostream>
#include <algorithm>
#include <vector>
auto fast_io = [] {std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
return 0; }();

class Solution {
public:
     void nextPermutation(std::vector<int>& nums) {

          std::next_permutation(begin(nums), end(nums));
     }
};