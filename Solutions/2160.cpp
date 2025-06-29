// 2160. Minimum Sum of Four Digit Number After Splitting Digits

#include <vector>
#include <algorithm>

class Solution {
public:
     int minimumSum(int num) {

		std::vector<int> p{};
		p.reserve(4);

		while (num>0)
		{
			p.emplace_back(num % 10);
			num /= 10;
		}

		std::sort(begin(p), end(p));

		int n1 = p[0] * 10 + p[2];
		int n2 = p[1] * 10 + p[3];

		return n1 + n2;
     }
};