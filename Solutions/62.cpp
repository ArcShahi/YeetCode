// 62. Unique Paths

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
	int uniquePaths(int m, int n) {

		long long paths{ 1ll };
		for (int i{ 1 }; i <= m - 1; ++i)
			paths = paths * (n - 1 + i) / i;

		return static_cast<int>(paths);
	}
};