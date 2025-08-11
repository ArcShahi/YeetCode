// 17. Letter Combinations of a Phone Number

#include <string>
#include <vector>
#include <unordered_map>

// TIME COMPLEXITY : O(3^n*4^n)
// SPACE COMPLEXITY : O(3^n*4^n)

// RECURSIVE BACKTRACK
class Solution {
public:
	std::vector<std::string> letterCombinations(std::string digits) {

		if (digits.empty())return{};
		combination.clear();
		curr.clear();
		backtrack(digits, 0);
		return combination;
	}
private:
	const std::unordered_map<char, std::string> keypad{
		{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},
		{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"} };

	std::vector<std::string> combination{};
	std::string curr{};

	void backtrack(const std::string& digits, size_t idx)
	{
		if (idx == digits.size())
		{
			combination.push_back(curr);
			return;
		}
		for (const auto& letter : keypad.at(digits[idx]))
		{
			curr.push_back(letter);
			backtrack(digits, idx + 1);
			curr.pop_back();
		}
	}
};
// ITERATIVE BACKTRACK

class Solution {
public:
	std::vector<std::string> letterCombinations(const std::string& digits)
	{
		if (digits.empty()) return {};

		std::vector<std::string> result{ "" }; 
		for (char digit : digits)
		{
			std::vector<std::string> next{};
			for (const auto& combination : result) 
				for (const auto& letter : keypad.at(digit)) 
					next.push_back(combination + letter);
		
			result.swap(next); // move to the next "level"
		}
		return result;
	}

private:
	const std::unordered_map<char, std::string> keypad{
	    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
	    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
	};
};
