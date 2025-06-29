// 2037. Minimum Number of Moves to Seat Everyone
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
// TIMPE COMPLEXITY : O(nlogn)
// SPACE COMPLEXITH : O(1)



// THE INPUT size is always [1,100] so we can use brute force

class Solution {
public:
     int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {

          std::ranges::sort(seats);
          std::ranges::sort(students);

          int count = std::inner_product(seats.begin(), seats.end(), students.begin(), 0,
               std::plus<>(),[](const auto  a, const auto b) { return std::abs(a - b); });

          return count;
     }
};


class Solution2 {
public:
     int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {

          std::ranges::sort(seats);
          std::ranges::sort(students);

          int count{ 0 };

          for (int i{ 0 }; i < seats.size(); ++i)
          {
               count += std::abs(seats[i] - students[i]);
          }
          return count;
     }
};