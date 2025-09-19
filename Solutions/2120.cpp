// 2120. Execution of All Suffix Instructions Staying in a Grid

#include <string>
#include <vector>

// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(1) ; ignoring  the return value

class Solution {
public:
     std::vector<int> executeInstructions(int n, std::vector<int>& startPos, std::string s) {

          robot = { startPos[0],startPos[1] };
          bound = n;

          const size_t grid{ s.size()};
          std::vector<int> arr(grid);

          for (size_t i{ 0 }; i < grid; ++i){
               int exe{ 0 };
               for (size_t j{ i }; j < grid; ++j){

                    walk(s[j]);
                    if (!in_bounds()){
                    }
                    ++exe;
               }
               arr[i] = exe;
               robot = { startPos[0],startPos[1] }; // reset postion
          }

          return arr;
     }
private:
     struct Vec2 { int x{}, y{}; };
     Vec2 robot{};
     int bound{ 0 };
     void walk(char cmd)
     {
          switch (cmd)
          {
          case 'U': --robot.x; break;
          case 'D': ++robot.x; break;
          case 'R': ++robot.y; break;
          case 'L': --robot.y; break;
          default:
               break;
          }
     }
     bool in_bounds()
     {
          return (robot.x >= 0 && robot.x < bound &&
               robot.y >= 0 && robot.y < bound);
     }
   
};