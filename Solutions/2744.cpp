// 2744. Find Maximum Number of String Pairs

#include <string>
#include <vector>

// TIME COMPLEXITY : O(N*N); 
// SPACE C0MPLEXITY  : O(1)


class Solution {
public:
     int maximumNumberOfStringPairs(std::vector<std::string>& words) {

          int count{ 0 };
          const auto n{ words.size() };

          for (size_t i{ 0 }; i < n; ++i)
               for (size_t j{ i + 1 }; j < n; ++j)
                    if (words[i][0] == words[j][1] && words[i][1] == words[j][0]) ++count;

          return count;
     }
};
