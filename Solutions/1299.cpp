
// 1299. Replace Elements with Greatest Element on Right Side

#include <vector>


// Iterate backwards -> save current element , replace current element with max, update max

class Solution {
public:
     std::vector<int> replaceElements(std::vector<int>& arr) {

          int max{ -1 };

          for (auto itr{ rbegin(arr) }; itr != rend(arr); ++itr)
          {
               auto temp{ *itr };
               *itr = max;
               max = std::max(temp, max);
          }

          return arr;
     }
};