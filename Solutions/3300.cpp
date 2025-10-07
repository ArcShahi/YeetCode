// 3300. Minimum Element After Replacement With Digit Sum

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(Nlog(max(x)) , x is max digit of a number
// SPACE COMPLEXITY : O(1)

int digig_sum(int x)
{
	int sum{ 0 };
	for (; x; x /= 10)
		sum += x % 10;
	
	return sum;
}

class Solution {
public:
     int minElement(std::vector<int>& nums) {

		int min{ std::numeric_limits<int>::max() };

		std::for_each(begin(nums), end(nums), [&](auto& x)
			{
				x = digig_sum(x);
				min = std::min(min, x);
			});
		return min;
     }
};