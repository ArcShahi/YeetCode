// 3248. Snake in Matrix

#include <string>
#include <vector>


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
     int finalPositionOfSnake(int n, std::vector<std::string>& commands) {

		int i{}, j{};
		// The grid is flipped on Coord plane
		for (const auto& cmd : commands)
		{    
			if (cmd[0] == 'U') --i;
			else if (cmd[0] == 'D') ++i;
			else if (cmd[0] == 'R') ++j;
			else --j;
		}

		return (i * n) + j;
     }
	
};

/*

    0  1  2
0 [ 1  2  3 ]
1 [ 4  5  6 ]
2 [ 7  8  9 ]


00 Origin -> '1' grid is sitting on origin
*/