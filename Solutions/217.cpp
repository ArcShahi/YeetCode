// 217. Contains Duplicate

#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
     bool containsDuplicate(std::vector<int>& nums)
     {
          std::unordered_map<int, int> hash_map{ 0 };

          for (auto& i : nums)
          {
               hash_map[i]++;
               if (hash_map[i] == 2)
                    return true;
          }

          return false;

     }
};


// OTHER WAYS ( SORT THEN SEARCH, USE UNORDERED SET ) , IGNORE RUNTIME FOR THIS ONE IT SUCKS