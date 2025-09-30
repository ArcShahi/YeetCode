// 2657. Find the Prefix Common Array of Two Arrays

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)


class Solution {
public:
     std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {

          const size_t n{ A.size() };
          std::vector<int> freq(n);
          std::vector<int> c(n);
          int common{};
          for (size_t i{ 0 }; i < n; ++i)
          {
               if (++freq[A[i]] == 2) ++common;
               if (++freq[B[i]] == 2) ++common;

               c[i] = common;
          }
          return c;
     }
};