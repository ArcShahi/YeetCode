// 2942. Find Words Containing Character
#include <vector>
#include <string>


class Solution {
public:
	std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
		std::vector<int> count{};

		for (size_t i = 0; i < words.size(); i++)
			if (words[i].contains(x)) count.push_back(i);
		
		return count;
	}
};
