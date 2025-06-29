
// 232. Implement Queue using Stacks

#include <vector>

class MyQueue {
private:
     std::vector<int> in{};
     std::vector<int> out{};

public:
     MyQueue(int n=100) {
          in.reserve(n);
          out.reserve(n);
     }

     void push(int x) {
          in.push_back(x);
     }

     int pop() {

          if (out.empty())
          {
               io();
          }
          auto val{ out.back() };
          out.pop_back();
          return val;
     }

     int peek() {
         
          if (out.empty())
          {
               io();
          }
          return out.back();
     }

     bool empty() 
     {
          return in.empty() && out.empty();
     }

private:
     void io()
     {
          while (!in.empty())
          {
               out.push_back(in.back());
               in.pop_back();
          }
     }
};

// IT's C++ you can get away with 0ms even by using single vector ( FUCK LEETCODE )