// 1754. Largest Merge Of Two Strings

#include <string>
#include <string_view>

// TIME COMPLEXITY : O(N+M)
// SPACE COMPLEIXTY :O(1)

// IO IS SLOWING DOWN RUNTITIME 

class Solution {
public:
     std::string largestMerge(std::string word1, std::string word2) {    
          std::string merger{};
          
          int i{ 0 }, j{ 0 };
          while (i<word1.length() && j<word2.length())
          {
               auto first{ std::string_view(word1).substr(i) };
               auto sec{ std::string_view(word2).substr(j) };
               if (first > sec) merger += word1[i++];
               else merger += word2[j++];
          }
          while (i < word1.size()) merger += word1[i++];
          while (j < word2.size()) merger += word2[j++];
          return merger;

     }
};