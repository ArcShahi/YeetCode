// 2410. Maximum Matching of Players With Trainers

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(Nlogn)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {

          std::sort(begin(players), end(players));
          std::sort(begin(trainers), end(trainers));

          auto p{ begin(players) };
          auto t{ begin(trainers) };

          int count{ 0 };

          while (p!=end(players) && t !=end(trainers))
          {
               if (*p <= *t)
               {
                    ++p;++t;
                    ++count;
               }
               else ++t;
          }
          return count;
     }
};