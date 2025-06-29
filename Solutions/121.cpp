// 121. Best Time to Buy and Sell Stock

#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices) {


		int price = std::numeric_limits<int>::max();
		int profit = 0;

		for (const auto& i : prices)
		{
			price = std::min(i, price);
			profit = std::max(profit, i - price);
		}
		return profit;

	}
};
