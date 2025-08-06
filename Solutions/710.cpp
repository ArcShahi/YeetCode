// 710. Random Pick with Blacklist

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>

class Solution {
public:
     Solution(int n, std::vector<int>& blacklist)
     {
          int b = blacklist.size();
          limit = n - b ;

          blocked.insert(begin(blacklist), end(blacklist));

          int last{ n - 1 };
          for (const auto& val : blacklist)
          {
               if (val < limit)
               {
                    while (blocked.count(last))
                         --last;

                    map[val] = last--;
               }
          }
     }

     int pick() {
            
          int r{ rand() % limit };
          if (map.count(r))
               return map[r];

          return r;
     }
    
private:
     std::unordered_set<int> blocked{};
     std::unordered_map<int, int> map{};
     int limit{};
};