// 2481. Minimum Cuts to Divide a Circle

class Solution {
public:
     int numberOfCuts(int n) {

          if (n == 1) return 0;
          // When circle is divided into even portions we only need half the lines ( as diameters )
          return !(n & 1) ? n >> 1 : n;
     }
};