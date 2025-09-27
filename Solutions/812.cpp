// 812. Largest Triangle Area

#include <vector>

// TIME COMPLEXITY : O(N^3)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
	double largestTriangleArea(std::vector<std::vector<int>>& points) {

		double largest{ 0 };
		const size_t n{ points.size() };

		// Using shoelace algorithm
		for (size_t i = 0; i < n; ++i)
		{
			int x1{ points[i][0] }, y1{ points[i][1] };

			for (size_t j = i + 1; j < n; ++j)
			{
				int x2{ points[j][0] }, y2{ points[j][1] };

				for (size_t k = j + 1; k < n; ++k)
				{
					int x3{ points[k][0] }, y3{ points[k][1] };

					auto area = 0.5 * std::abs(
						x1 * (y2 - y3) +
						x2 * (y3 - y1) +
						x3 * (y1 - y2));

					largest = std::max(largest, area);
				}
			}
		}

		return largest;
	}
};