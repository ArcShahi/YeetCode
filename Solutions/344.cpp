// 344. Reverse String

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     void reverseString(std::vector<char>& s) {
          std::ranges::reverse(s);
     }
};

// 2 POINTERS
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)
class Solution {
public:
     void reverseString(std::vector<char>& s) {
         
          auto l{ begin(s) },r{ end(s) - 1 };

          for (; l < r; ++l, --r)
               std::iter_swap(l, r);
     }
};

// RECURSIION , why tho ?
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N) ;  stack usage

class Solution {
public:
     void reverseString(std::vector<char>& s) {

          reverse(s, 0, s.size() - 1);
     }
     void reverse(std::vector<char>& s, int l, int r)
     {
          if (l>r) return;        
          std::swap(s[l], s[r]);
          reverse(s, l+1, r-1);
     }
};
