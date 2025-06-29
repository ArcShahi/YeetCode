// 2094. Finding 3-Digit Even Numbers

#include <vector>

/*
* Instead of generating all 3-digit numbers and checking if they're valid(BRUTE FORCE),
 doing the opposite:
 why not  Generate all valid combinations directly from the given digits.
*/
class Solution {
public:
     std::vector<int> findEvenNumbers(std::vector<int>& digits)
     {
          std::vector<int> result{};
          int count[10] = {};

          for (int d : digits) count[d]++;

          // try all 3-digit combinations
          for (int i = 100; i <= 998; i += 2) 
          {
               int f = i / 100;
               int s = (i / 10) % 10;
               int t = i % 10;

               count[f]--; count[s]--; count[t]--;

               // check if to ensure valid 3 Digit nums
               if (count[f] >= 0 && count[s] >= 0 && count[t] >= 0) {
                    result.push_back(i);
               }

               count[f]++; count[s]++; count[t]++;
          }

          return result;
     }

};