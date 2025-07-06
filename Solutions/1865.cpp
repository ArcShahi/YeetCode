// 1865. Finding Pairs With a Certain Sum

#include <vector>
#include <unordered_map>
#include <algorithm>

class FindSumPairs {
public:
     FindSumPairs(std::vector<int>&nums1, std::vector<int>& nums2) {
         
          x = nums1;
          y = nums2;

          for (const auto& i : nums2)
               ++hashmap[i];
     }

     void add(int index, int val) {
          --hashmap[y[index]];
          y[index] += val;
          ++hashmap[y[index]];
     }

     int count(int tot) {

          int count{};
          for (const auto& i : x)
          {
               int n = tot - i;
               if (hashmap.count(n))
                    count += hashmap[n];
          }

          return count;
     }

private:
     std::unordered_map<int, int> hashmap{};
     std::vector<int> x, y{};
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */