// 1310. XOR Queries of a Subarray

#include <vector>
#include <numeric>
#include <functional>
#include <iterator>

// TIME COMPLEXITY : O(N+Q)
// SPACE COMPLEXITY : O(N+Q)

class Solution {
public:
     std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {

          prexor.reserve(arr.size());
          std::partial_sum(begin(arr), end(arr),std::back_inserter(prexor), std::bit_xor<int>());

          std::vector<int> out{};
          out.reserve(queries.size());

          for (const auto& q : queries)
               out.push_back(ranged_xor(q[0], q[1]));

          return out;
     }

private:
     std::vector<int> prexor{};

     int ranged_xor(int l, int r)
     {
          int right{ prexor[r] };
          int left{ l > 0 ? prexor[l - 1] : 0 };
          return right ^ left;
     }
};