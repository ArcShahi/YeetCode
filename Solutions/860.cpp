// 860. Lemonade Change

#include <vector>

class Solution {
public:
	bool lemonadeChange(std::vector<int>& bills) {

		int five{ 0 }, ten{ 0 };

		for (const auto& bill : bills)
		{

			if (bill == 5) ++five;
			else if (bill == 10) ++ten;

			int change{ bill - 5 };

			if (change == 0) continue;
			if (change == 5)
			{
				if (five) --five;
				else return false;
			}
			else
			{
				if (five && ten) // Greedy Prefer 10 + 5 , over 5x3
				{
					--five;
					--ten;
				}
				else if (five >= 3) five -= 3;
				else return false;
			}
		}

		return true;
	}
};