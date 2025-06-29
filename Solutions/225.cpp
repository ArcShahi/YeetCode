
#include <vector>

// F U C K  L E E T C O D E 

class MyStack {
public:
     std::vector<int> buffer{};

     MyStack(int n=100) {
          buffer.reserve(n);
     }

     void push(int x) {
          buffer.push_back(x);
     }

     int pop() {
          int val = top();
          buffer.pop_back();
          return val;
     }

     int top() {
          return buffer.back();
     }

     bool empty() {

          return buffer.empty();
     }
};

