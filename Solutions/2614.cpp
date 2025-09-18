// 2614. Prime In Diagonal

#include <vector>

bool is_prime(int n) 
{
     if (n < 2) return false;          
     if (n == 2 || n == 3) return true;
     if (n % 2 == 0 || n % 3 == 0) return false;

     for (int i = 5; i * 1LL * i <= n; i += 6) 
     {
          if (n % i == 0 || n % (i + 2) == 0)
               return false;
     }
     return true;
}

// TIME COMPLEXITY : O(Nsqrt(M))
// SPACE COMPLEXITY : O(1)

class Solution {
public:
     int diagonalPrime(std::vector<std::vector<int>>& nums) {

          int prime{ -69240 };
          size_t n{ nums.size() };

          for (size_t i{ 0 };i< n; ++i)
          {
               int lr{ nums[i][i] }, rl{ nums[n - i - 1][i] };
               if (is_prime(lr))
                    prime = std::max(prime, lr);

               if (is_prime(rl))
                    prime = std::max(prime, rl);
          }
          return prime;
     }
};

