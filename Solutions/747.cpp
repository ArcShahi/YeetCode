// 747. Largest Number At Least Twice of Others

#include <algorithm>
#include <vector>

class Solution {
public:
	int dominantIndex(std::vector<int>& nums) {

		auto maximum{ std::max_element(begin(nums), end(nums)) };
		int index = std::distance(begin(nums), maximum);

		// std::all_of()
		for (const auto& i : nums)
		{
			if (i == *maximum) continue;

			if (!(*maximum >= 2 * i)) return -1;
		}

		return index;


	}
};

/*

int dominantIndex(std::vector<int>& nums) 
{

		auto max= std::max_element(begin(nums), end(nums));
		int index = std::distance(begin(nums), max);

		bool is_dominant = std::all_of(begin(nums), end(nums), [&max](int i) {
			return i == *max || *max >= 2 * i;
		});

		return is_dominant ? index : -1;
	}

*/