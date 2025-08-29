// 3021. Alice and Bob Playing Flower Game


/* we've to find every combination of x and y where x=[1,n] y=[1,m] their sum is not even 
*/

// TIME COMPLEXTIY : O(1)
//SPACE COMPLEXITY : O(1)

class Solution {
public:
     long long flowerGame(int n, int m) {

          return 1ll * n * m / 2;
     }
};