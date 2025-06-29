
#include <vector>
#include <unordered_map>


/*
 Count how many times each number appears. If a number appears n times,
  then n * (n – 1) // 2 good pairs can be made with this number.
*/


// TIME COMPLEXITY : O(n)
// SPACE COMPLEIXTY : O(n)

class Solution {
public:
	int numIdenticalPairs(std::vector<int>& nums) {

		int count{ 0 };

		std::unordered_map<int, int> hashmap{};

		for (const auto& i : nums)
			hashmap[i]++;

		for (const auto [k, n] : hashmap)
			count = count + n * (n - 1) / 2;

		return count;
	}
};
class Solution2 {
public:
	int numIdenticalPairs(std::vector<int>& nums) {

		int count{ 0 };
		// IILE
		const auto hashmap=[&nums] {
	      std::unordered_map<int, int> temp{};
	      for (const auto& i : nums) ++temp[i];
	      return temp;
           }(); // Declared and called IILE


		for (const auto [k, n] : hashmap)
			count = count + n * (n - 1) / 2;

		return count;
	}
};
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY: O(1);
class Solution3 {
public:
	int numIdenticalPairs(std::vector<int>& nums) {

		int count{ 0 };
		for (int i{ 0 }; i < nums.size() - 1; ++i)
		{
			for (int j{ i + 1 }; j < nums.size(); ++j)
			{
				if (nums[i] == nums[j])
				{
					++count;
				}
			}
		}

		return count;
	}
};
