// 3443. Maximum Manhattan Distance After K Changes
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
	int maxDistance(std::string s, int k) {
		int dis{ 0 };

		std::vector<std::string> direction{ "NE", "NW", "SE", "SW" };

		for (auto& dir : direction)
		{
			int coord{ 0 };
			int bad{ 0 };

			for (auto c : s)
			{
				if (dir.find(c) != std::string::npos)
					++coord;
				else
					--coord, ++bad;

				dis = std::max(dis, coord+2 * std::min(k, bad));
			}
		}
		
		return dis;
	}
};
#include <iostream>
int main()
{
	Solution sln{};

	std::cout << sln.maxDistance("NWNE", 1);
}