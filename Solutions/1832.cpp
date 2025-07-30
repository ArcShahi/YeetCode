// 1832. Check if the Sentence Is Pangram

#include <string>
#include <algorithm>

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1) ( Cuz we just have to count lowercase chars

class Solution {
public:
     bool checkIfPangram(std::string sentence) {

          bool arr[26]{};
          for (const auto c : sentence)  arr[c - 'a']=true;
          return std::all_of(arr, arr + 26, [](const int x) {return x >= 1; });
     }
};