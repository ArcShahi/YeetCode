// 1518. Water Bottles

// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int numWaterBottles(int numBottles, int numExchange) {
          return numBottles + (numBottles - 1) / (numExchange - 1);
     }
};

