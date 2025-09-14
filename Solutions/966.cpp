// 966. Vowel Spellchecker

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// TIME COMPLEXITY : O(N+QL)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
     std::vector<std::string> spellchecker(std::vector<std::string>& wordlist,
          std::vector<std::string>& queries) {

          std::unordered_map<std::string, std::string> lookup{};
          lookup.reserve(wordlist.size());

          for (const auto& word : wordlist) 
          {
               // exact
               lookup.emplace('0' + word, word);

               // lowercase
               auto low{ into_lower(word) };
               if (!lookup.count('1' + low)) {
                    lookup['1' + low] = word;
               }

               // masked
               auto mask{ mask_vowel(low) };
               if (!lookup.count('2' + mask))
               {
                    lookup['2' + mask] = word;
               }
          }

          std::vector<std::string> result{};
          result.reserve(queries.size());

          for (const auto& q : queries) 
          {
               if (auto it{ lookup.find('0' + q)}; it != end(lookup))
               {
                    result.push_back(it->second);
               }
               else if (auto it = lookup.find('1' + into_lower(q)); it != end(lookup))
               {
                    result.push_back(it->second);
               }
               else if (auto it{ lookup.find('2' + mask_vowel(into_lower(q)))};
                    it != end(lookup))
               {
                    result.push_back(it->second);
               }
               else 
               {
                    result.push_back("");
               }
          }

          return result;
     }

private:
     bool is_vowel(char x) {
          return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
     }

     std::string into_lower(const std::string& str) {
          auto res{ str };

          std::ranges::transform(res, begin(res), 
               [](unsigned char c) { return std::tolower(c); });
          return res;
     }

     std::string mask_vowel(const std::string& str) {
          auto res{ str };

          std::ranges::transform(res, begin(res),
               [&](unsigned char c) { return is_vowel(c) ? '*' : c; });
          return res;
     }
};





class Solution {
public:
     std::vector<std::string> spellchecker(std::vector<std::string>& wordlist,
          std::vector<std::string>& queries) {

          const size_t n{ wordlist.size() };

          std::unordered_set<std::string> dict{};
          dict.reserve(n);
          std::unordered_map<std::string, std::string> lowers{};
          lowers.reserve(n);
          std::unordered_map<std::string, std::string> vowels{};
          vowels.reserve(n);

          for (const auto& word : wordlist) {
               dict.insert(word);

               auto low = into_lower(word);
               if (!lowers.count(low)) lowers[low] = word;

               auto mask = mask_vowel(low); // always mask from lowercase
               if (!vowels.count(mask)) vowels[mask] = word;
          }

          std::vector<std::string> checked;
          checked.reserve(queries.size());

          for (const auto& q : queries) {
               if (dict.count(q))
               {
                    checked.push_back(q);
               }
               else 
               {
                    auto low = into_lower(q);

                    if (auto it = lowers.find(low); it != end(lowers))
                    {
                         checked.push_back(it->second);
                    }
                    else if (auto it = vowels.find(mask_vowel(low)); it != end(vowels)) {
                         checked.push_back(it->second);
                    }
                    else {
                         checked.push_back("");
                    }
               }
          }

          return checked;
     }

private:
     bool is_vowel(char x) {
          return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
     }

     std::string into_lower(const std::string& str) {
          std::string res = str;
          std::transform(begin(res), end(res), begin(res),
               [](unsigned char c) { return tolower(c); });
          return res;
     }

     std::string mask_vowel(const std::string& str) {
          std::string res = str;
          transform(begin(res), end(res), begin(res),
               [&](unsigned char c) { return is_vowel(c) ? '*' : c; });
          return res;
     }
};
