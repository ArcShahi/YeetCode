
// 3110. Score of a String


#include <string>

class Solution {
public:
     int scoreOfString(std::string s) 
     {
          int score{ 0 };

          for (int i{ 0 }; i < s.length() - 1; ++i)
               score = score + abs((s[i]) - s[i + 1]);

               return score;

     }
};

