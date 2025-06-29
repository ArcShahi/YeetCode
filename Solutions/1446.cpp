// 1446. Consecutive Characters

#include <string>

class Solution {
public:
     int maxPower(std::string s)
     {
          int cache{ 0 };
          int count{ 0 };

          char pvs{};


          for (const auto& i : s)
          {
               if (i == pvs)
               {
                    ++cache;
               }
               else
               {
                    pvs = i;
                    cache = 1;
               }
               count = std::max(cache, count);

          }

          return count;
     }
};


