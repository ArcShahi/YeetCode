// 49. Group Anagrams

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>

class Solution {
     
public:
     std::vector<std::vector<std::string>> 
          groupAnagrams(std::vector<std::string>& strs)
     {

          std::vector<std::vector<std::string>> group{};
          std::unordered_map<std::string, std::vector<std::string>> hashmap{};
          hashmap.reserve(strs.size());

          for (const auto& word : strs)
          {
               auto key{ encode_freq(word) }; // encodes frequence : cat -> a1c1t1
               hashmap[key].push_back(word);
          }
          
          for (auto& [key, words] : hashmap)
               group.push_back(std::move(words));

          return group;

     }

  
private:

     std::string encode_freq(const std::string& word)
     {
          std::array<int, 26> count{};

          for (const auto& c : word)
               ++count[c - 'a'];

          std::string key{};

          for (int i{ 0 }; i < 26; ++i)
          {
               if (count[i] > 0)
               {
                    key += static_cast<char>(i + 'a') + std::to_string(count[i]);
               }
          }

          return key;
     }
};


#pragma GCC optimize("O3")

class Solution2 {
public:
     std::vector<std::vector<std::string>>
          groupAnagrams(std::vector<std::string>& strs)
     {
          std::unordered_map<std::string, std::vector<std::string>> hashmap{};
          hashmap.reserve(strs.size());

          for (const auto& word : strs) {
               auto key{ word };
               std::ranges::sort(key);
               hashmap[key].push_back(word);
          }

          std::vector<std::vector<std::string>> result{};
          result.reserve(hashmap.size());

          for (auto& [key, words] : hashmap) {
               result.push_back(std::move(words));
          }

          return result;
     }
};

// You can also hybridize it  choose key bases on string size