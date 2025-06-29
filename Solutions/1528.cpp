// 1528. Shuffle String

#include <vector>
#include <string>

// TIME COMPLEXITY :O(n)
// SPACE COMPLEXITH :O(n), if ignoring the return value then O(1)

class Solution {
public:
     std::string restoreString(std::string s, std::vector<int>& indices) {

          std::string shuffle(s.length(), '0');
          for (int i{ 0 }; const auto& c:s)
               shuffle[indices[i++]] = c;
          
          return shuffle;
     }
};