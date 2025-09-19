// 1910. Remove All Occurrences of a Substring

#include <string>
// TIME COMPLEXITY : O(N*M)
// SPACE COMPLEXITY: O(M)


class Solution {
public:
     std::string removeOccurrences(std::string s, std::string part) {


          std::string rem{};
          rem.reserve(s.size());

          const auto n{ part.length() };

          for (const auto& c : s)
          {
               rem.push_back(c);
               const auto len{ rem.size() };

               // check if last n elements on "stk" are equal to part
               if (len >= n && rem.compare(len - n, n, part) == 0)
                    rem.erase(len - n, n);
          }
          rem.shrink_to_fit();
          return rem;
     }
};

// Compare last n parts only when stk.size()>=n , if their last part is equal remove it