// 2315. Count Asterisks

#include <string>

// TIME COMPELXITY : O(N)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
	int countAsterisks(std::string s) {

		int star{};
		int bar{};

		for (const auto c : s)
		{
			if (c == '*' && bar % 2 == 0) ++star;
			else if (c == '|') ++bar;
		}

		return star;
	}
};