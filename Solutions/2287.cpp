// 2287. Rearrange Characters to Make Target String
#include <string>
#include <unordered_map>

class Solution {
public:
     int rearrangeCharacters(std::string s, std::string target) {

          std::unordered_map<char, int> h1{};

          for (const auto& c : s)
               ++h1[c];

          std::unordered_map<char, int> h2{};
          for (const auto& c : target)
               ++h2[c];

          int min=s.length(); // initial min can't be more than chars ( INT_MAX )

          for (const auto& [k, v] : h2)
               min = std::min(min, h1[k] / v);
          
          return min;
        
     }
};

// USING IIFE

