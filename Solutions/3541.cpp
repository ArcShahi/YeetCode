// 3541. Find Most Frequent Vowel and Consonant

#include <string>

bool is_vowel(char ch)
{
     static const std::string vowel{ "aeiou" };
     return vowel.find(ch) != std::string::npos;
}

class Solution {
public:
     int maxFreqSum(std::string s) {

          int alpha[26]{};
          int vowels{ 0 };
          int con{ 0 };

          for (const auto c : s) alpha[c - 'a']++;
     
          for (int i{ 0 }; i < 26; ++i)
          {
               if (is_vowel(i +'a'))
                    vowels = std::max(alpha[i], vowels);
               else
                    con = std::max(alpha[i], con);   
          }
          return vowels + con;
     }
};