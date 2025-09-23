// 500. Keyboard Row

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <array>

// TIME COMPLEXITY : O(N*M)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     std::vector<std::string> findWords(std::vector<std::string>& words) {

          std::vector<std::string> typed{};
          // row 1:  qwertyuiop defauts to 0 
          for (const char c : std::string("asdfghjkl")) arr[c - 'a'] = 1;
          for (const char c : std::string("zxcvbnm")) arr[c - 'a'] = 2;

          for (const auto& word : words)
               if (predicate(word)) typed.push_back(word);

          return typed;
     }
private:
  
     std::array<int, 26> arr{};

     bool predicate(std::string_view s)
     {
          int row{ -1 };
          for (auto c : s)
          {
               auto l{ std::tolower(c) };
               if (row == -1) row = arr[l - 'a'];
               else if (arr[l - 'a'] != row) return false;
          }
          return true;
     }
};



// NAIVE SOLUTION


class Solution {
public:
     std::vector<std::string> findWords(std::vector<std::string>& words) {

          std::vector<std::string> typed{};

          for (const auto& word : words)
          {
               bool f{ true }, s{ true }, t{ true };

               for (const auto c : word)
               {
                    char lower = std::tolower(c);
                    if (f && !row1.contains(lower)) f = false;
                    if (s && !row2.contains(lower)) s = false;
                    if (t && !row3.contains(lower)) t = false;

                    if (!f && !s && !t) break;
               }
               if (f || s || t) typed.push_back(word);
          }

          return typed;
     }
private:
     std::unordered_set<char> row1{ 'q','w','e','r','t','y','u','i','o','p' };
     std::unordered_set<char> row2{ 'a','s','d','f','g','h','j','k','l' };
     std::unordered_set<char> row3{ 'z','x','c','v','b','n','m' };

};