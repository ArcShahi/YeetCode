// 703. Kth Largest Element in a Stream

#include <vector>
#include <queue>

class KthLargest {
public:
     KthLargest(int k, std::vector<int>& nums)
          :kth{k}
     {
          for (const auto& num : nums) add(num);
     }

     int add(int val) {

          pq.push(val);
          if (pq.size() > kth) pq.pop();
          return pq.top();
     }

private:

     std::priority_queue<int, std::vector<int>, std::greater<int>> pq{};
     int kth{};
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */