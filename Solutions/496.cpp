// 496. Next Greater Element I

#include <iostream>
#include <vector>

// TIME COMPLEXITY : O(n*m)
class Solution {
public:
     std::vector<int> nextGreaterElement(std::vector<int>& num1, std::vector<int>& num2) 
     {
          std::vector<int> arr{};
          arr.reserve(num1.size());    

          for (const auto& i : num1)
          {
               // find the postion of 'i'(num1) element in num2
               auto elem = std::find(begin(num2), end(num2), i);

               // search only the right side for larger element 
               auto next_greater = std::find_if(elem, end(num2), [&i](int x)
                    {
                         return i < x;
                    });

               // if next greater found...
               if (next_greater != end(num2)) arr.push_back(*next_greater);
               else arr.emplace_back(-1);

          }
          return arr;
     }
};

