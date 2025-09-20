// 1475. Final Prices With a Special Discount in a Shop

#include <vector>

// TIME COMPLEXITY : O(N*N)
// SPACE COMPLEXITY : O(1) ; ignoring return value

class Solution {
public:
     std::vector<int> finalPrices(std::vector<int>& prices) {

          const auto n{ prices.size() };
          std::vector<int> out(n);

          for (size_t i{ 0 }; i < n; ++i)
          {
               int discount{ 0 };
               for (size_t j{ i + 1 }; j < n; ++j)
               {
                    if (prices[j] <= prices[i])
                    {
                         discount = prices[j];
                         break;
                    }
               }
               out[i] = prices[i] - discount;
          }

          return out;
     }
};


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<int> finalPrices(std::vector<int>& prices) {

          const auto n{ prices.size() };
          std::vector<int> out(n);
          std::vector<int> stk{};

          for (int i= n - 1; i >= 0; --i)
          {
               while (!stk.empty() && stk.back() > prices[i])
                    stk.pop_back();

               int discount{ stk.empty() ? 0 : stk.back() };
               out[i] = prices[i] - discount;
               stk.push_back(prices[i]);
          }
          return out;
     }
};
