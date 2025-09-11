// 2785. Sort Vowels in a String

#include <string>
#include <algorithm>
#include <iterator>
#include <array>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::string sortVowels(std::string s) {
          std::string vowels{};
          vowels.reserve(s.length());

          std::array<int, 52> freq{};

          auto is_vowel = [](char x) { static const std::string v{ "aeiouAEIOU" };
          return v.find(x) != std::string::npos; };


          for (auto& c : s)
          {
               if (is_vowel(c)) {
                    if (islower(c)) ++freq[c - 'a'];
                    else ++freq[c - 'A' + 26];
                    c = '#';
               }
          }

          // uppercase vowels first
          for (char c : std::string{ "AEIOU" }) {
               vowels.append(freq[c - 'A' + 26], c);
          }

          // lowercase vowels
          for (char c : std::string{ "aeiou" }) {
               vowels.append(freq[c - 'a'], c);
          }


          auto it{ begin(vowels) };
          std::ranges::for_each(s, [&](char& c)
               {
                  if (c == '#') c = *it++;
               });
        
          return s;
     }
};


// TIME COMPLEXITY : O(Nlogn)
// SPACE COMPLEXITY : O(n)

class Solution {
public:
     std::string sortVowels(std::string s) {
          std::string vowels{};
          vowels.reserve(s.length());

          auto is_vowel{ [](char x) {static const std::string v{"aeiouAEIOU"};
               return v.find(x) != std::string::npos; } };

          for (auto& c : s) {
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






