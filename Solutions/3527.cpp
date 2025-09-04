// 3527. Find the Most Common Response

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

// TIME COMPLEXITY : O(N*M)
// SPACE COMPLEXITY : O(N*M)

class Solution {
public:
     std::string findCommonResponse(std::vector<std::vector<std::string>>& responses) {
          
          std::unordered_map<std::string, int> hmap{};
          hmap.reserve(1000);
          std::unordered_set<std::string> set{};
          std::string s{};
          int c{ 0 };

          for (const auto& response : responses)
          {
               set.clear();
               // / C++23 : set.insert_range(response) , LeetCode doesn't support it yet
               for (const auto& msg : response) set.insert(msg);
               for (const auto& i : set)
               {
                    int count = ++hmap[i];

                    if (c < count || (c == count && i < s))
                    {
                         s = i;
                         c = count;
                    }
               }
          }

          return s;
     }
};