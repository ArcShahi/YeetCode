// 2108. Find First Palindromic String in the Array

#include <vector>
#include <string>
#include <algorithm>


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY : O(1)

bool is_palindrome(const std::string& s)
{
     auto l{ begin(s) }, r{ end(s) - 1 };
     while (l < r)
          if (*l++ != *r--) return false;
     return true;
}

class Solution {
public:
     std::string firstPalindrome(std::vector<std::string>& words) {

          auto it{ std::ranges::find_if(words, is_palindrome) };
          return it != end(words) ? *it : "";
     }
};