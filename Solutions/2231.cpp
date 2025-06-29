//  2231. Largest Number After Digit Swaps by Parity
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:

     int largestInteger(int num) 
     {

          std::vector<char> even{};
          std::vector<char> odd{};
          // reserve space for vector to decrease run time
       

          std::string s{ std::to_string(num) };

          for (char c : s)
          {
               int digit = c - '0';
               if (digit & 1) odd.push_back(digit);
               else even.push_back(digit);
          }

          std::sort(rbegin(even), rend(even));
          std::sort(rbegin(odd), rend(odd));


          int etr{ 0 };
          int otr{ 0 };

          for (int i{ 0 }; i < s.length(); ++i)
          {
               int digit = s[i] - '0';

               if (digit & 1)
               {
                    s[i] = odd[otr++];
               }
               else
               {
                    s[i] = even[etr++];
               }
          }

          return std::stoi(s);
     }
};

