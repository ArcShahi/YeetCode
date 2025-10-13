// 1598. Crawler Log Folder

#include <vector>
#include <string>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(1)

class Solution {
public:
	int minOperations(std::vector<std::string>& logs) {

		int op{ 0 };
		for (const auto& log : logs)
		{
			if (log == "../") op = std::max(0, op - 1);
			else if (log != "./") ++op;
		}
		return op;
	}
};


