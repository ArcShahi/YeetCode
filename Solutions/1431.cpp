// 1431. Kids With the Greatest Number of Candies
#include <vector>
#include <algorithm>
#include <ranges>

class Solution {
public:
     std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {

          std::vector<bool> kids(candies.size(), false);
          const int max{ *std::ranges::max_element(candies) };    
          for (int i{ 0 }; const auto& c:candies)
               kids[i++] = (c + extraCandies >= max);
             
          return kids;
         
     }
};
// C++23 Views MAY NOT RUN OF LEETOCODE

class Solution {
public:
     std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {

          std::vector<bool> kids(candies.size(), false);
          const int max{ *std::ranges::max_element(candies) };     

          for (auto [i, c] : std::views::enumerate(candies))
               kids[i] = (c + extraCandies >= max);
         
          return kids;
     }
};