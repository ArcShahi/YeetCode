// 204. Count Primes

#include <algorithm>

// TIME COMPLEXITY :O(NloglogN)
// SPACE COMPLEIXTY: O(N)

// not using std::vector<bool> cuz of it's nuisance and weirdness

class Solution {
public:
     int countPrimes(int n) {
          // Sieve of Eratosthenes
          if (n < 3) return 0;
        
          bool* sieve{ new bool[n] };
          std::memset(sieve, 1, n);
          sieve[0] = sieve[1] = false;

          for (int i = 2; i * i < n; ++i)
               for (int j = sieve[i] ? i * i : n; j < n; j += i) // if(sieve[i]) for {}...
                    sieve[j] = false;

          int count=std::count(sieve+2, sieve + n, 1);
          delete[] sieve;
          return count;
     }
};

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode