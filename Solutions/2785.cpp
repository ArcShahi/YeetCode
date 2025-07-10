// 2785. Sort Vowels in a String

#include <string>
#include <algorithm>
#include <iterator>


// TIME COMPLEXITY : O(Nlogn)
// SPACE COMPLEXITY : O(n)

class Solution {
public:
     std::string sortVowels(std::string s) {
          std::string vowels{}; 
          vowels.reserve(s.length());

          auto is_vowel{ [](char x) {static const std::string v{"aeiouAEIOU"};
               return v.find(x) != std::string::npos; } };

          for (auto& c : s){
               if (is_vowel(c)) {
                    vowels.push_back(c);
                    c = '#';
               }
          }
          std::sort(begin(vowels), end(vowels));
          auto it{ begin(vowels) };

          for (auto& c : s)
               if (c == '#')
                    c = *it++;

          return s;
     }
};




