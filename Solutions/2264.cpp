// 2264. Largest 3-Same-Digit Number in String

#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
	std::string largestGoodInteger(std::string num) {

		char good{};
		for (int i{ 0 }; i < num.length() - 2; ++i)
			if (num[i] == num[i + 1] && num[i] == num[i + 2])
				if (good < num[i])good = num[i];

		return good ? std::string(3, good) : "";
	}
};
