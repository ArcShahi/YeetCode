// 1678. Goal Parser Interpretation
#include <string>
#include <algorithm>

// TIME COMPLEXITY :O(n)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     std::string interpret(std::string command) {

          std::string goal{};
          for (int i{ 0 }; i < command.length();)
          {
               if (command[i] == 'G')
               {
                    goal.push_back(command[i++]);
               }
               else if (command[i] == '(' && command[i + 1] == ')')
               {
                    goal.push_back('o');
                    i += 2;
               }
               else if (command[i] == '(' && command[i + 1] == 'a')
               {
                    goal += "al";
                    i += 4;
               }
          }
          return goal;
     }
};
     
