// 941. Valid Mountain Array


#include <iostream>
#include <vector>

#pragma GCC optimize("Ofast")

class Solution 
{
public:
     // IO can slow runtime 
     Solution()
     {
          std::ios::sync_with_stdio(false);
          std::cin.tie(nullptr);
          std::cout.tie(nullptr);
     }

     bool validMountainArray(std::vector<int>& arr)
     {
          int destiny = arr.size();

          if (destiny < 3)  return false;

          int peak{};
          // Climb only if next exists and it's greater
          while (peak + 1 < destiny && arr[peak] < arr[peak + 1]) ++peak;

          if (peak == 0 || peak == destiny - 1)  return false;

          // Get down only if next step exists and it's smaller
          while (peak + 1 < destiny && arr[peak + 1] < arr[peak]) ++peak;

          // Did we reach the end ?
          return peak == destiny - 1;
     }
};