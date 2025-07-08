// 599. Minimum Index Sum of Two Lists

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
      
public:
     Solution() {
          std::ios::sync_with_stdio(false);
          std::cin.tie(nullptr);
     }

     std::vector<std::string> findRestaurant(
          const std::vector<std::string>& list1,
          const std::vector<std::string>& list2
     ) 
     {
          std::unordered_map<std::string, int> index_map{};
          index_map.reserve(list1.size());

          for (int i = 0; i < list1.size(); ++i) {
               index_map[list1[i]] = i;
          }

          std::vector<std::string> result{};

          int min_sum = INT_MAX;

          for (int i = 0; i < list2.size(); ++i)
          {
               auto it = index_map.find(list2[i]);
               if (it != index_map.end())
               {
                    int sum = i + it->second;
                    if (sum < min_sum)
                    {
                         result.clear();
                         result.push_back(list2[i]);
                         min_sum = sum;
                    }
                    else if (sum == min_sum)
                    {
                         result.push_back(list2[i]);
                    }
               }
          }

          return result;
     }
};
