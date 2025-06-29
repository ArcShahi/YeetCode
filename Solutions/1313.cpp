
// 1313. Decompress Run - Length Encoded List

#include <vector>

class Solution {
public:
     std::vector<int> decompressRLElist(std::vector<int>& nums) {
          std::vector<int> v{};

          for (int i{ 0 }; i < nums.size(); i+=2)
               v.insert(end(v), nums[i + 1], nums[i]);

          return v;
     }
};