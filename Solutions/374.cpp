// 374. Guess Number Higher or Lower


/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
// API FORWARD DECLARATION

int guess(int num);

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)

class Solution {
public:
     int guessNumber(int n) {

          if (n == 1) return 1;

          int start{ 1 };
          int end{ n };

          while (start<=end)
          {
               int num{ start + (end - start) / 2 };
               int cmd{ guess(num) };
               if (cmd == 0) return num;
               else if (cmd == 1) start = num + 1;
               else end = num - 1;
          }
          return -1;
     }
};