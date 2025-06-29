// 1486. XOR Operation in an Array


int xor_seq(int x) {
     if (x % 4 == 0) return x;
     if (x % 4 == 1) return 1;
     if (x % 4 == 2) return x + 1;
     return 0;
}

class Solution {
public:
 
     int xorOperation(int n, int start) {
          int s = start >> 1;
          int val = xor_seq(s + n - 1) ^ xor_seq(s - 1);
          return (val << 1) | (n & start & 1);
     }
};
