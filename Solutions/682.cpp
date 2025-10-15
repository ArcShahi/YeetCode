// 682. Baseball Game

#include <string>
#include <vector>
#include <numeric>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
	int calPoints(std::vector<std::string>& operations) {

		std::vector<int> v{};

		for (const auto op : operations)
		{
			if (op == "+")
			{
				auto n{ v.size() - 1 };
				v.push_back(v[n] + v[n - 1]);
			}
			else if (op == "D") v.push_back(v.back() * 2);
			else if (op == "C") v.pop_back();
			else v.push_back(std::stoi(op));
		}

		return std::accumulate(begin(v), end(v), 0);
	}
};