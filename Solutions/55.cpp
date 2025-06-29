//55. Jump Game

 
#include <vector>

// TIME COMPLEXITY :O(n)
// SPACE COMPLEXITH :O(1)

/*

  iterate backwards...

  index is always one step before goal.. 
  if the nums[i]+i >=goal means we can reach the goal from that index... 

  so our new goal is now 'i'th index

  and we can reach new the new goal from one before index .. means we can reach the new goal too
   and so on...

   if goal==0 meaning we've travelled from end to start and if can travel backwards .. 
   we can travel forward

   Values: [2,3,1,1,4]
   Index:  [0,1,2,3,4] 
                  i ^ goal


   if we can reach it then move the goal to the left

   [0,1,2,3,4]
        i ^goal


 ================


  Value : [3,2,1,0,1] 
  Index : [0,1,2,3,4]
                 i ^goal

  we can't reah goal from that index... so we just return false

   
*/

class Solution {
public:
     bool canJump(std::vector<int>& nums) {

          int goal = nums.size() - 1;
         
          for (int i{ goal - 1 }; i >= 0; --i)
               if (nums[i] + i >= goal)
                    goal = i;

          return goal == 0;
         
     }
};