// 1436. Destination City

#include <vector>
#include <string>
#include <unordered_map>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(N)

class Solution {
public:
     std::string destCity(std::vector<std::vector<std::string>>& paths) {

          std::unordered_map<std::string, std::string> hashmap{};
          for (const auto& path : paths)
               hashmap[path[0]] = path[1];

          for (const auto& [s, d] : hashmap)
               if (!hashmap.count(d)) return d;
          
          return "";
     }
};