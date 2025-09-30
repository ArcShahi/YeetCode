// 771. Jewels and Stones

#include <string>
#include <unordered_set>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
	int numJewelsInStones(std::string jewels, std::string stones) {

		std::unordered_set set(begin(jewels), end(jewels));
		return std::ranges::count_if(stones, [&](char x) {return set.contains(x); });
	}
};