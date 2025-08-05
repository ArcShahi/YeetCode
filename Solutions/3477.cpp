// 3477. Fruits Into Baskets II

#include <vector>
#include <unordered_set>

// TIME COMPLEXITY : O(N*M)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
          const int n = baskets.size();
          int count{ n };
         
          for(const auto& fruit:fruits)
               for( auto& basket:baskets)
                    if (fruit <= basket)
                    {
                         basket = 0; // mark as placed
                         --count;
                         break;
                    } 
          return count;
     }
};