// 1381. Design a Stack With Increment Operation
#include <vector>
#include <algorithm>


class CustomStack {
public:
     CustomStack(int maxSize)
          :cap{ maxSize }
     {      
          stk.reserve(cap);
     }

     void push(int x) {       
          if (stk.size() != cap) stk.push_back(x);
     }

     int pop() {
          if (stk.empty()) return -1;
          auto xval{ stk.back() };
          stk.pop_back();
          return xval;
     }

     void increment(int k, int val) {       
          int lim = std::min(k,static_cast<int>(stk.size()));
          for (int i{ 0 }; i < lim; ++i)
               stk[i] += val;
     }
private:
     std::vector<int> stk{};
     int cap{};
};
