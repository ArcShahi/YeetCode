// 2278. Percentage of Letter in String

#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
	int percentageLetter(std::string s, char letter) {

		return std::ranges::count(s, letter) * 100 / s.length();
	}
};