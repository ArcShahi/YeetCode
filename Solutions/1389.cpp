// 1389. Create Target Array in the Given Order

#include <vector>

class Solution {
public:
     std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {

          std::vector<int> v{};
          for (int i{ 0 }; nums.size(); ++i)
               v.insert(begin(v)+index[i], nums[i]);
         
          return v;
     }
};


class Solution2 {
public:
     std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
          std::vector<int> target;

          for (int i = 0; i < nums.size(); ++i) 
          {
               target.push_back(0);

               // Shift elements to the right from the end to index[i]
               for (int j = target.size() - 1; j > index[i]; --j) {
                    target[j] = target[j - 1];
               }

               target[index[i]] = nums[i];
          }

          return target;
     }
};