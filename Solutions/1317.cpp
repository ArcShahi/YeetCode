// 1317. Convert Integer to the Sum of Two No-Zero Integers

#include <vector>

// TIME COMPLEXITY : O(nLogn)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     std::vector<int> getNoZeroIntegers(int n) {

          std::vector<int> v{};
           
          for (int i{ 1 }; i <= n / 2; ++i)
          {
               int x{ i }, y{ n - i };

               if (!has_zero(x) && !has_zero(y))
                    return { x,y };
          }
          return { -1,-1 };
     }

private:
     bool has_zero(int x)
     {
          if (x % 10 == 0) return true;
          for (; x > 0; x /= 10) if (x % 10 == 0) return true;
          return false;
     }
};

