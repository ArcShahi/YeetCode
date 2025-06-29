// 1784. Check if Binary String Has at Most One Segment of Ones

#include <string>

class Solution {
public:
	bool checkOnesSegment(std::string s)
	{
		bool ZR{ 0 };

		for (auto c : s)
		{
			if (c == '0')
			{
				ZR = true;
			  /* we can add a `continue;` here cuz c can't be both 1 and 0 at the same time,
			     it's not a quantum computer
			  */ 
			}
             // found 1 after 0 so it's not contiguous
			if (ZR && c == '1')
			{
				return false;
			}
		}

		return true;
	}
};