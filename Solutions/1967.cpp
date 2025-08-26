// 1967. Number of Strings That Appear as Substrings in Word

#include <vector>
#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(N*M*L)
// SPACE COMPLEXITY : O(1)
// where N : length of patterns, L = lenght of word, M = max length of patterns[i]

class Solution {
public:
     int numOfStrings(std::vector<std::string>& patterns, std::string word) {

          return std::ranges::count_if(patterns, [&word](const auto x){
                    return word.contains(x);
               });
     }
};