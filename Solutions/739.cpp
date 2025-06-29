
#include <vector>

class Solution {
public:
     std::vector<int> dailyTemperatures(std::vector<int>& tem) {

          std::vector<int> days(tem.size());

          std::vector<int> stack{};

          for (int i{ 0 }; i < tem.size(); ++i)
          {
               // if stack is not empty and current temp is hotter than what stacks tells us
               while (!stack.empty() && tem[stack.back()]<tem[i])
               {
                    int pvs{ stack.back() };
                    stack.pop_back();

                    days[pvs] = i - pvs;
               }
               stack.push_back(i);
          }
          
          return days;

     }
};

