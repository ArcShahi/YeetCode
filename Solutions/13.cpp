// 13. Roman to Integer

#include <string>
#include <unordered_map>
class Solution {
public:
	int romanToInt(const std::string& roman)
	{
		static const std::unordered_map<char, int> hashtable
		{
			{'M',1000},{'D',500},{'C',100},{'L',50},
			{'X',10},{'V',5},{'I',1}
		};

		int pvs{ 0 };
		int dec{ 0 };

		for (int i=roman.size() - 1 ; i>=0; --i)
		{
			int dig = hashtable.at(roman[i]);
			dec = (dig < pvs) ? dec - dig : dec + dig;
			pvs = dig;
		}
		return dec;
	}


};