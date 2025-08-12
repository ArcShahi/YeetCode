// 877. Stone Game

#include <vector>

 /* 
  Alice always wins ... she knows if she selects first row  then third, 
 fifth is hers(every even index
 if she slects last then every odd index is hers..

 our question is can she wins ? yes she can... Let's say every even index is black and 
 every odd index is white. if we sum them one is of course going to be large. Cuz in constrains it's
 said we can't draw so even!=odd.

   She wins cuz she has the freedom to select first every time.
   Visualize the game in your mind or paper and you can see...

   
   [e,o,e,o,e,o]
   [6,9,4,2,1,3]

   e=6+4+1=11;
   o=9+2+3=14;

   if she selects first row(0th index ) she will get even index only after that
   if she selects last  row(n-1 index ,Piles are even so last index is odd )
   she will get odd index only after that

   And she's clever enough to clock that...

   


 */ 

class Solution {
public:
     bool stoneGame(std::vector<int>& piles) {

          return true;

     }
};