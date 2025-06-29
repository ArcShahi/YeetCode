// 1051. Height Checker

#include <vector>
#include <algorithm>

class Solution {
public:

	int heightChecker(std::vector<int>& h)
	{

		auto e{ h };
		// students are expected to stand is ascending order...
		std::sort(begin(e), end(e));
        

		int counter{ 0 };

		// Just count how many students are not in correct order
		for (int i{ 0 }; i < h.size(); ++i)
		{
			if (e[i] != h[i]) ++counter;
		}

		return counter;
	}
};