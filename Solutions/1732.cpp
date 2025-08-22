// 1732. Find the Highest Altitude

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int largestAltitude(std::vector<int>& gain) {

          int altitude{0};
          int max_altitude{ 0 };
    
          for (const auto& g : gain)
          {
               altitude += g;
               max_altitude = std::max(max_altitude, altitude);
          }

          return max_altitude;      
     }
};