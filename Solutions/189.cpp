//189. Rotate Array

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)
class Solution {
public:
     void rotate(std::vector<int>& nums, int k) {
          // Reduce the number of steps cuz `k==num.size()` gives same vector
          k %= nums.size();
          std::rotate(rbegin(nums), rbegin(nums) + k, rend(nums));
     }
};

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

class Solution2 {
public:
     void rotate(std::vector<int>& nums, int k) {

          k %= nums.size();
          std::reverse(begin(nums), end(nums));
          std::reverse(begin(nums), begin(nums) + k);
          std::reverse(begin(nums) + k, end(nums));
     }
};


/*
 ROTATE LEFT

        int n = nums.size();
        k %= n;  // Handle k > n

        // Step 1: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 2: Reverse remaining n - k elements
        reverse(nums.begin() + k, nums.end());

        // Step 3: Reverse whole array
        reverse(nums.begin(), nums.end());
    }
};


*/