// 896. Monotonic Array

#include <vector>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
	bool isMonotonic(std::vector<int>& nums) {

		bool inc{ false }, dec{ false };

		for (int i = 1; i < nums.size(); ++i)
		{
			int x{ nums[i - 1] }, y{ nums[i] };

			if (x < y) inc = true;
			else if (y < x) dec = true;

			if (inc && dec) return false; // we can't have both incrementing and decrementing
		}
		return true;
	}
};

// We ignore x==y or y==x cuz that can be both incresing or decreasing