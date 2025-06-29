// 2396. Strictly Palindromic Number

#include <iostream>
// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(1)

// Also it's broken... you can just return false and it will work
class Solution {
public:
     bool isStrictlyPalindromic(int n) {

          int base = n - 2;   
          std::string nums{};

          while (n>0)
          {
               int q = n / base;
               int r = n % base;

               nums.push_back(r + '0');
               n = q;
          }

          // Test for palimdrome

          auto l{ begin(nums) };
          auto r{ end(nums) - 1 };

          while (l<r)
          {
               if (*l != *r) return false;

               ++l;
               ++r;
          }
          return true;
     }
};

