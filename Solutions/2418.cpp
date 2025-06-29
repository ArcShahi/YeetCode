// 2418. Sort the People
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

// TIME COMPLEXITY : O(nlogn)
// SPACE COMPLEXITY : O(n)

class Solution {
public:
     std::vector<std::string> sortPeople(std::vector<std::string>& names,
          std::vector<int>& heights) {
          int n = names.size();

          std::vector<int> idx(n);
          std::iota(begin(idx), end(idx), 0);

          std::sort(begin(idx), end(idx), [&](const int x, const int y)
               {return heights[y] < heights[x]; });

          std::vector<std::string> people{};
          people.reserve(n);
          for (const auto& i : idx)
               people.push_back(names[i]);

          return people;
     }
};


class Solution2 {
public:
     std::vector<std::string> sortPeople(std::vector<std::string>& names,
          std::vector<int>& heights) {

          int n = names.size();
          std::vector<std::pair<int, std::string>> p{};
          p.reserve(n);

          for (int i{ 0 }; i < names.size(); ++i)
               p.push_back({ heights[i],names[i] });

          std::sort(begin(p), end(p), [](const auto& x, const auto& y)
               {return y.first < x.first; });

          std::vector<std::string> people{};
          people.reserve(n);
          for (const auto& i : p)
               people.push_back(i.second);
               
          return people;
     }
};


class Solution3 {
public:
     std::vector<std::string> sortPeople(std::vector<std::string>& names,
          std::vector<int>& heights) {
          int n = names.size();
          std::map<int, std::string, std::greater<>> hashmap{};
          for (int i{ 0 }; i < n; ++i)
               hashmap[heights[i]] = names[i];

          std::vector<std::string> people{};
          people.reserve(n);
          for (const auto& h : hashmap)
               people.push_back(h.second);

          return people;
     }
};