// 2433. Find The Original Array of Prefix Xor

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1) if ignoring return value


class Solution {
public:
     std::vector<int> findArray(std::vector<int>& pref) {

          int n = pref.size();
          std::vector<int> arr(n, 0);
          arr[0] = pref[0];

          for (int i{ 1 }; i < n; ++i)
               arr[i] = pref[i - 1] ^ pref[i];

          return arr;
     }
};

// INPLACE : WE must iterate backwards
// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(1)

class Solution {
public:
     std::vector<int> findArray(std::vector<int>& pref) {

          for (int i = pref.size() - 1; i > 0; --i)
               pref[i] = pref[i] ^ pref[i - 1];
          
          return pref;
     }
};
