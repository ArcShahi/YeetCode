// 3168. Minimum Number of Chairs in a Waiting Room
#include <string>


// Return the max number of people sitting cuz that's how many chairs we need
class Solution {
public:
     int minimumChairs(std::string s) {

          int max_chair{ 0 };
          // No people sitting initially
          int chair{ 0 };

        
          for (auto c : s)
          {
               if (c == 'E')
               {
                   // person sits
                    chair++;
               }
               else
               {     // Person leaves
                    --chair;
               }
               max_chair = std::max(max_chair, chair);
          }
          return max_chair;
     }
};

