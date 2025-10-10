// 1207. Unique Number of Occurrences

#include <vector>
#include <unordered_set>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
//SPACE COMPLEXITY : O(N)


class Solution {
public:
     bool uniqueOccurrences(std::vector<int>& arr) {

          std::unordered_map<int, int> hmap{};
          for (const auto& i : arr)
               ++hmap[i];

          std::unordered_set<int> set{};
          for (const auto& e : hmap)
          {
               if (set.contains(e.second))
                    return false;
               set.insert(e.second);
          }
                
          return true;
     }
};