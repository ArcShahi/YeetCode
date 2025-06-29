// 1952. Three Divisors

class Solution {
public:
     bool isThree(int n)
     {
          int count{ 0 };

          int i{1};

          // We only need to test till half
          while (i<=n/2)
          {
               //  if divisible ( equivalent to n % i==0 )
               if (!(n % i++)) ++count;

               // if count is alread above 3
               if (count > 3) return false;
          }

          return count == 3;      
     }
};

// SOLUTIN 2

/*

  bool isThree(int n) 
  {
        int root = sqrt(n);
        if (root * root != n) return false; // Not a perfect square

        // Now check if root is prime
        for (int i = 2; i * i <= root; ++i)
            if (root % i == 0)
                return false;

        return root > 1;
    }



*/