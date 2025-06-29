//

#include <string>
#include <algorithm>

namespace rng = std::ranges;

class Solution {

public:
	int maxDiff(int num)
	{
		auto s{ std::to_string(num) };
		auto max_str{ s };

		if (auto itr{ rng::find_if(max_str,[](char c)
			{return c != '9'; }) }; itr != end(max_str))
		{
			auto idx{ *itr };
			rng::replace(max_str, idx, '9');
		}

		auto min_str{ s };
		if (s.front() != '1') {
			rng::replace(min_str, s.front(), '1');
		}
		else
		{
			if (auto itr = std::find_if(begin(min_str) + 1, end(min_str),
				[](char c) {return c != '0' && c != '1'; }); itr != end(min_str))
			{
				auto idx{ *itr };
				rng::replace(min_str, idx, '0');
			}
		}

		return std::stoi(max_str) - std::stoi(min_str);
	}
};


// IIFE


