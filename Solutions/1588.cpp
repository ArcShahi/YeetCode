// 1588. Sum of All Odd Length Subarrays

#include <vector>

// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int sumOddLengthSubarrays(std::vector<int>& arr) {

          int sum{ 0 };
          const size_t n{ arr.size() };

          for (size_t i{ 0 }; i < n; ++i)
          {
               int curr{ 0 };
               for (size_t j{ i }; j < n; ++j)
               {
                    curr += arr[j];
                    sum += (j - i + 1) & 1 ? curr : 0;
               }
          }
          return sum;         
     }
};