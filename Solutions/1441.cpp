// 1441. Build an Array With Stack Operations

#include <vector>
#include <string>

class Solution {
public:
     std::vector<std::string> buildArray(std::vector<int>& target, int n) {
          std::vector<std::string> arr;
          arr.reserve(n*2);

          int curr{ 1 };  // stream always  starts with 1
          for (int i{ 0 }; i < target.size(); ++i) 
          {
               while (curr < target[i]) {
                    arr.push_back("Push");
                    arr.push_back("Pop");
                    ++curr;
               }

               arr.push_back("Push");
               ++curr;
          }

          return arr;
     }
};


