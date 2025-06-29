// 977. Squares of a Sorted Array
#include <vector>


class Solution {
public:
	std::vector<int> sortedSquares(std::vector<int>& vec)
	{

		std::vector<int> res(vec.size());

		auto l = cbegin(vec);
		auto r = cend(vec) - 1;
		auto itr = rbegin(res); // Iterates res backwards and writes elements

		while (l <= r)
		{
			if (abs(*l) < abs(*r))
			{
				*itr = (*r) * (*r);
				--r;
			}
			else
			{
				*itr = (*l) * (*l);
				++l;
			}

			++itr;

		}

		return res;

	}


};