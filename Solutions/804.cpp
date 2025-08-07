// 804. Unique Morse Code Words

#include <vector>
#include <string>
#include <unordered_set>

// TIME COMPLEXITY : O(N*L)
// SPACE COMPLEXITY : O(1)

/*
If we denote the total number of words as N and the average length of each word as L, but the
constrain is small so it doesn't matter

*/
class Solution {
public:
	int uniqueMorseRepresentations(std::vector < std::string >& words) {

		const std::vector<std::string> morse{
          ".-",   "-...", "-.-.", "-..",  ".", "..-.", "--.",  "....",
          "..",   ".---", "-.-",  ".-..", "--", "-.",   "---",  ".--.",
          "--.-", ".-.",  "...",  "-",    "..-","...-", ".--",  "-..-",
          "-.--", "--.."
		};

		std::unordered_set<std::string> transform{};
		for (const auto& word : words)
		{
			std::string s{};
			for (const auto& ch : word)
				s += morse.at(ch % 'a');

			transform.insert(s);
		}
		return transform.size();
	}
};