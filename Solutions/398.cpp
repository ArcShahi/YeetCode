// 398. Random Pick Index

#include <vector>

// TIME COMPLEXITY : O(N)

class Solution {
public:
     Solution(std::vector<int>& nums)
          :vec{ nums } {
     }

     int pick(int target) {
          int reservoir{ -1 };
          int p{ 0 };

          for (int i = 0; i < vec.size(); ++i)
          {
               if (vec[i] == target)
               {
                    ++p;
                    if (rand() % p == 0) reservoir = i;
               }
          }

          return reservoir;
     }


private:
     std::vector<int> vec{};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */