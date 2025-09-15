// 1935. Maximum Number of Words You Can Type


#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <ranges>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int canBeTypedWords(const std::string& text, const std::string& brokenLetters) {
          std::bitset<26> broken{};
          for (char c : brokenLetters)  broken.set(c - 'a');

          int count{ 0 };
          for (auto&& word : text | std::views::split(' ')) 
               if (std::ranges::none_of(word, [&](char c) { return broken[c - 'a']; }))
                    ++count;

          return count;
     }
};

// TIME COMPLEXITY : O(N+M)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int canBeTypedWords(std::string text, std::string brokenLetters) {

          std::bitset<26> broken{};
          for (const auto& i : brokenLetters) broken.set(i - 'a');

          std::istringstream iss(text);
          std::string word{};
          int count{ 0 };

          while (std::getline(iss, word,' '))
               if (std::ranges::none_of(word, [&](char c) {return broken[c - 'a']; }))
                    ++count;

          return count;
    
     }
};

