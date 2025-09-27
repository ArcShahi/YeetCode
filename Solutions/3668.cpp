// 3668. Restore Finishing Order

#include <vector>
#include <unordered_set>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<int> recoverOrder(std::vector<int>& order, std::vector<int>& friends) {

          std::unordered_set set(begin(friends), end(friends));
          std::vector<int> v{};
          v.reserve(friends.size());

          for (const auto& o : order)
               if (set.contains(o)) v.push_back(o);
          
          return v;
     }
};
