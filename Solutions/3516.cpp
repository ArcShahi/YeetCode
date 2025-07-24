// 3516. Find Closest Person

#include <cmath>
#include <utility>

// TIME COMPLEXITY : 0(1)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
	int findClosest(int x, int y, int z) {

		int xz{ std::abs(z - x) }, yz{ std::abs(z - y) };
		return (xz == yz) ? 0 : (xz < yz) ? 1 : 2;

	}
};