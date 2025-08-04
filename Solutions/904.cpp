// 904. Fruit Into Baskets

#include <vector>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)
class Solution {
public:
     int totalFruit(std::vector<int>& fruits) {

          std::unordered_map<int, int> hashmap{};

          int i{ 0 };
          int max_fruit{ 0 };

          for (int j{ 0 }; j < fruits.size(); ++j)
          {
               ++hashmap[fruits[j]];

               while (hashmap.size() > 2)
               {
                    int curr{ fruits[i] };
                    --hashmap[curr];
                    if (hashmap[curr] == 0) hashmap.erase(curr);
                    ++i;
               }
               max_fruit = std::max(max_fruit, j - i + 1);
          }
          return max_fruit;
     }
};