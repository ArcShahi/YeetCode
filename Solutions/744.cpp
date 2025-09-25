// 744. Find Smallest Letter Greater Than Target

#include <vector>
#include <algorithm>

// TIME COMPLEXITY : O(logN)
// SPACE COMPLEXITY : O(1)


class Solution {
public:
     char nextGreatestLetter(std::vector<char>& letters, char target) {

          auto it{ std::ranges::upper_bound(letters,target) };
          return it != end(letters) ? *it : letters.front();
     }
};



class Solution {
public:
     char nextGreatestLetter(std::vector<char>& letters, char target) {

          int low = 0;
          int high = letters.size() - 1;
          while (low<=high)
          {
               int mid = low + (high - low) / 2;

               if (target < letters[mid]) high = mid - 1;
               else low = mid + 1;
          }

          return letters[low % letters.size()];
     }
};
class Solution {
public:
     char nextGreatestLetter(std::vector<char>& letters, char target) {

          int low = 0;
          int high = letters.size() - 1;
          while (low<=high)
          {
               int mid = low + (high - low) / 2;

               if (target < letters[mid]) high = mid - 1;
               else low = mid + 1;
          }

          return letters[low % letters.size()];
     }
};