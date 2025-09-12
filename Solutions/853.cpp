// 853. Car Fleet

#include <vector>
#include <algorithm>


// TIME COMPLEXITY : O(nLogn)
// SPACE COMPLEXITY : O(n)


class Solution {
public:
     int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {

          if (position.size() == 1) return 1;

          std::vector<std::pair<int, int>> cars{};
          cars.reserve(position.size());

          for (int i{ 0 };i <position.size(); ++i)
               cars.emplace_back(position[i], speed[i]);


          std::ranges::sort(cars, [](const auto& a, const auto& b)
               {return a.first>b.first; });

          std::vector<double> stk{};

          for (const auto& [pos, s] : cars)
          {
               double time_taken{ static_cast<double>(target - pos) / s };
               if (stk.empty() || stk.back() < time_taken) 
                    stk.push_back(time_taken);
          }

          return stk.size();
     }
};


/*

 DRAW IT ON PAPER TO VISULAIZE IT

 Time taken is stored in Monotonic Incrasing stack .

 If time taken is less meaning it can become fleet ( we dont' count it cuz it'll one of fleet )

 stk.back() < time_taken  if false meaning they'll become fleet and travel together

 After coming side by side the faster car matches the speed of slower car.


*/