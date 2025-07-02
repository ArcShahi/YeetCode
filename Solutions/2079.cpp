// 2079. Watering Plants

#include <vector>

class Solution {
public:
     int wateringPlants(std::vector<int>& plants, int capacity) {

          int steps{ 0 };
          int can{ capacity };
          for (int i{ 0 }; i < plants.size(); ++i)
          {
               if (plants[i] > can)
               {
                    steps += i * 2;
                    can = capacity;
               }
               can -= plants[i];
               ++steps;
          }
          return steps;
     }
};
