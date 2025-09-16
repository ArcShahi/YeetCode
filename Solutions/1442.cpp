// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

#include <vector>
#include <numeric>
#include <functional>

class Solution {
public:
     int countTriplets(std::vector<int>& arr) {
          int n = arr.size();
          std::vector<int> prexor(n + 1, 0);

          //  prexor[1..n] 
          std::inclusive_scan(begin(arr), end(arr), begin(prexor) + 1, std::bit_xor<int>());

          int count{ 0 };

          for (int i = 0; i < n; ++i) 
               for (int k = i + 1; k < n; ++k) 
                    if (prexor[i] == prexor[k + 1])
                         count += (k - i);  // number of valid j's between i and k
                    
          return count;
     }
};
