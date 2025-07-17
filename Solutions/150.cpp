// 150. Evaluate Reverse Polish Notation

#include <vector>
#include <string>
#include <string_view>

int evaluate(int x, int y, char op)
{
     switch (op)
     {
     case '+': return x + y;
     case '-': return x - y;
     case '*': return x * y;
     case '/': return x / y; 
     default: return 0; 
     }
}

/*
  Iterate the tokens , keep pushing them onto stack , whenever operator is found, pop 2 values
  and perform the operation then push the result onto the stack.
*/


// TIME COMPLEXITY :O(N)
// SPACE COMPLEXITY :O(N)

class Solution {
public:
     int evalRPN(std::vector<std::string>& tokens) {
       
          std::vector<int> stk{};
          stk.reserve(tokens.size());

          for (const auto& i : tokens)
          {
               if (i.length()==1 && !isdigit(i[0]))
               {
                    auto r{ stk.back() }; stk.pop_back(); // right_op
                    auto l{ stk.back() }; stk.pop_back(); // left_op
                    stk.push_back(evaluate(l, r, i[0])); 
               }
               else
                    stk.push_back(std::stoi(i));             
          }
          return stk.back();         
     }
};
