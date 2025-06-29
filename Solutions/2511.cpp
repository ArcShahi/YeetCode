// 2511. Maximum Enemy Forts That Can Be Captured

#include <vector>

// SLIDING WINDOW

class Solution {
public:
     int captureForts(std::vector<int>& forts) {

          int l{ 0 };
          int count{ 0 };
        
          
          for (int r{ 0 }; r < forts.size(); ++r)
          {
               if (!forts[r]) continue;

               if (forts[l]+forts[r]==0) // meaning  l=-1 ,r=1 or vice versa ( can be captured )
               {
                    count = std::max(count, r-l-1);

               }
               l = r;
                       
          }
          return count;
     }
};

