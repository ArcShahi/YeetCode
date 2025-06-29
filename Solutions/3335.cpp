
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

class Solution {
public:
     int lengthAfterTransformations(std::string& s, int t)
     {
          int arr[26]{ 0 };

          for (auto c : s)
               arr[c - 'a']++;

          
          while (--t>0)
          {
               for (auto c : s)
               {
                    if (c != 'z')
                    {
                         arr[(c - 'a') + 1]++;
                    }
                    else
                    {
                         arr[0]++;
                         arr[1]++;
                    }

               }
          }
          
          long mod = std::pow(10, 9) + 7;
          auto total = std::accumulate(std::begin(arr), std::end(arr), 0);
        
          return total % mod;

     }
};


