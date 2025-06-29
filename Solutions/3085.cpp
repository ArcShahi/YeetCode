// 3085. Minimum Deletions to Make String K-Special
#include <string>
#include <unordered_map>

class Solution {
public:
     int minimumDeletions(std::string word, int k) {

          std::unordered_map<char, int> hashmap{};

          for (const auto& c : word)
               ++hashmap[c];

          


     }
};