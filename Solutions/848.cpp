// 848. Shifting Letters

#include <string>
#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
     std::string shiftingLetters(std::string s, std::vector<int>& shifts) {

      
          long long sum{ 0 };

          for (int i = s.length() - 1; i >= 0; --i)
          {
               sum += shifts[i];
               s[i] = 'a' + ((s[i] - 'a' + sum) % 26);
          }
        
          return s;
     }
};