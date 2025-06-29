// 20. Valid Parentheses

#include <stack>
#include <unordered_map>
#include <string>
#include <vector>

class Solution {
public:
     bool isValid(std::string s)
     {

          // cuz valid pairs can't have odd braces
          if (s.size() & 1) return false;

          std::vector<char> stack{};

          static const std::unordered_map<char, char> braces = {
              {')', '('},
              {']', '['},
              {'}', '{'}
          };

          for (char ch : s)
          {
               // If it's a closing bracket
               if (braces.count(ch))
               {
                    // Check if stack is empty or top is not the matching opening
                    if (stack.empty() || stack.back() != braces.at(ch)) 
                    {
                         return false;
                    }
                    stack.pop_back(); // matched
               }
               else 
               {
                    
                    stack.push_back(ch);
               }
          }

          // If stack is empty, all brackets matched
          return stack.empty();
     }
};

// We're using vector as stack interface cuz std::stack is slow uses std::deque as it's container.

/*
* 
   template<class T,class Container = std::deque<T>> 
   class stack;

*/