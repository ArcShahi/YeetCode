//  1346. Check If N and Its Double Exist

#include <unordered_set>
#include <vector>

// TIME COMPLEXITY : 0(n)

class Solution {
public:
     bool checkIfExist(std::vector<int>& arr) {

          std::unordered_set<int> hash_set{};

          for (const auto& i : arr)
          {    // If 2*i already exists or i is even and half of i exists
               if (hash_set.count(i<<1) || (i&1)==0 && hash_set.count(i>>1))
               {
                    return true;
               }
               hash_set.insert(i);
          }

          return false;
     }
};

// if( hash_set.count(i*2) || i%2==0 && hash_set.count(i/2)) 