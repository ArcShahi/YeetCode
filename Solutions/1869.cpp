// 1869. Longer Contiguous Segments of Ones than Zeros

#include <string>

class Solution {
public:
	bool checkZeroOnes(std::string s) {

		int c0{ 0 };
		int c1{ 0 };

		int max0{ 0 };
		int max1{ 0 };

		for (const auto c : s)
		{
			if (c == '1')
			{
				++c1;
				max1 = std::max(c1, max1);
				c0 = 0;
			}
			else
			{
				++c0;
				max0 = std::max(c0, max0);
				c1 = 0;
			}
		}
		return max0 < max1;

	}
};

