// 2843. Count Symmetric Integers

#include <string>

bool is_symmetric(int n)
{
     int len{ 0 };
     int digits[5]{};

     while (n>0)
     {
          digits[len++] = n % 10;
          n /= 10;
     }
     if (len & 1) return false;

     const int mid{ len / 2 };
     int left{ 0 }, right{ 0 };

     for (int i{ 0 }; i < mid; ++i)
     {
          left += digits[i];
          right += digits[i + mid];
     }
     return left == right;
}

// TIME COMPLEXITY : O(N.Log(N))
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int countSymmetricIntegers(int low, int high) {

          int count{ 0 };     
          for (int n{ low }; n <= high; ++n)
               if (is_symmetric(n))++count;

          return count;
     }
};