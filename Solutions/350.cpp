// 350. Intersection of Two Arrays II

#include <vector>
#include <unordered_map>
#include <algorithm>

// TIME COMPLEXITY : O(n+m)
// SPACE COMPLEXITY :O(min(n,m))

class Solution {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
	{

		auto flag = nums1.size() < nums2.size();

		// Reference to smaller vector
		const auto& vec = flag ? nums1 : nums2;

		std::vector<int> common{};
		auto size = flag ? nums1.size() : nums2.size();
		common.reserve(size);


		std::unordered_map<int, int> hashmap{};

		for (const auto& i : vec)
			hashmap[i]++;

		// Reference to larger vector
		const auto& v = flag ? nums2 : nums1;

		for (const auto& i : v)
		{
			if (hashmap[i]) // only insert when count is greater than zero
			{
				common.push_back(i);
				hashmap[i]--;
			}
		}

		return common;
	  
	}
};

// Approach 2
// TIME COMPLXITY : O(nlogn)
// SPACE COMPLEXITY : O(1)
class Solution2 {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::ranges::sort(nums1);
		std::ranges::sort(nums2);

		auto size= nums1.size() < nums2.size() ? nums1.size() : nums2.size();

		std::vector<int> common{};
		common.reserve(size);

		auto f{ begin(nums1) };
		auto s{ begin(nums2) };

		while (f<end(nums1) && s<end(nums2))
		{
			if (*f == *s)
			{
				common.push_back(*f);
				++f;
				++s;
			}
			else if (*f<*s)
			{
				++f;
			}
			else
			{
				++s;
			}
		}
		return common;
	}
};