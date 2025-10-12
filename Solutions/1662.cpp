// 1662. Check If Two String Arrays are Equivalent

#include <string>
#include <vector>

// TIME COMPLEXITY : O(M+N)
// SPACE COMPLEXITY : O(1)



class Solution {
public:
	bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {


		const auto m{ word1.size() };
		const auto n{ word2.size() };
		size_t x{}, p{};
		size_t y{}, q{};

		while (x < m && y < n)
		{
			if (word1[x][p++] != word2[y][q++]) return false;
	
			if (word1[x].length()<= p) ++x, p = 0;
			if (word2[y].length()<= q) ++y, q = 0;

		}

		return (x == m) && (y == n);
	}
};