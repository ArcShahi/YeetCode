// 3274. Check if Two Chessboard Squares Have the Same Color

#include <string>

// TIME COMPLEXITY : O(1)
// SPACE COMPLEXITY : O(1)

char color(const std::string& grid)
{
	int x{ grid[0] - 'a' + 1 }, y{ grid[1] - '0' };
	return (x + y) % 2 == 0 ? 'b' : 'w';
}

class Solution {
public:
	bool checkTwoChessboards(std::string coordinate1, std::string coordinate2) {

		return color(coordinate1) == color(coordinate2);
	}
};