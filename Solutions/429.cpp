// 429. N-ary Tree Level Order Traversal

#include <queue>


// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY :O(N)

class Solution {
public:
     std::vector<std::vector<int>> levelOrder(Node* root) {

          std::vector<std::vector<int>> vec{};
          if (!root) return vec;

          std::vector<int> lvl{};
          std::deque<Node*> q{ root };

          while (!q.empty())
          {
               auto width{ q.size() };
               
               while (width-->0)
               {
                    const auto it{ q.front() }; q.pop_front();
                    lvl.push_back(it->val);

                    for (const auto& child : it->children)
                         if (child) q.push_back(child);
               }
               vec.push_back(lvl);
               lvl.clear();
          }

          return vec;
     }
};