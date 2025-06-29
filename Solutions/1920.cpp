// 1920. Build Array from Permutation

#include <vector>


class Solution {
public:
     std::vector<int> buildArray(std::vector<int>& nums) {

		std::vector<int> permute{};
		permute.reserve(nums.size());

		for (int i{ 0 }; i < nums.size(); i++)
			permute.push_back(nums[nums[i]]);

		return permute;
     }
};