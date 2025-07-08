// 414. Third Maximum Number

#include <vector>
#include <algorithm>


class Solution {
public:
     int thirdMax(std::vector<int>& nums) 
     {

          if (nums.size() == 1)
               return nums[0];
         
          // HAD TO USE long cuz Test cases inlcude INT_MIN
          long f{LONG_MIN}, s{LONG_MIN}, t{LONG_MIN};



          for (const auto& i : nums)
          {
               if (f == i || s == i || t == i) continue;

               if (f < i)
               {    
                    t = s;
                    s = f;
                    f = i;
               }
               else if (s < i)
               {
                    t = s;
                    s = i;
               }
               else if(t<i)
               {
                    t = i;
               }
          }

          return t == LONG_MIN ? f : t;
     }
};


/*

 ANOTHER SOLUTION BUT ABOVE IS FASTER 

  int thirdMax(std::vector<int>& nums) 
  {

          if (nums.size() == 1)
               return nums[0];


          std::set<int, std::greater<>> set{ nums.begin(),nums.end() };

          if (set.size() < 3) return *set.begin();

          return *std::next(set.begin(), 2);
     }

*/