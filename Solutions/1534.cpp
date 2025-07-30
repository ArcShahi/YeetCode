// 1534. Count Good Triplets

#include <vector>

// TIME COMPLEXITY : O(N^3)
// SPACE COMPLEXITY : O(1)

// Constriant is small we can use BRUTE FORCE

class Solution {
public:
     int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {

          int count{ 0 };        
          const int n=std::ssize(arr);

          for (int i{ 0 }; i < n; ++i)
               for (int j{ i + 1 }; j < n; ++j)
                    for (int k{ j + 1 }; k < n; ++k)
                         if (std::abs(arr[i] - arr[j]) <= a && std::abs(arr[j] - arr[k]) <= b
                              && std::abs(arr[i] - arr[k]) <= c)
                              ++count;

          return count;
     }
};