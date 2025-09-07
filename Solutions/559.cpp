// 559. Maximum Depth of N-ary Tree

#include <vector>
#include <deque>

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

// Iterative DFS PRE-ORDER
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
     int maxDepth(Node* root) {

          if (not root) return 0;

          std::vector<std::pair<Node*, int>> stk{ {root,1}};
          int max_depth{ 0 };

          while (!stk.empty())
          {
               const auto [node, depth] {stk.back()}; stk.pop_back();
               max_depth = std::max(max_depth,depth);

               for (const auto& child : node->children)
                    if (child) stk.push_back({ child,depth + 1 });
          }
          return max_depth;
     }
};

// BFS
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)


class Solution {
public:
     int maxDepth(Node* root) {

          if (not root) return 0;
          std::deque<Node*> q{root};
          int depth{ 0 };

          for (; !q.empty(); ++depth)
          {
               auto width{ q.size() };
               while (width-->0)
               {
                    const auto it{ q.front() }; q.pop_front();
                    for (const auto& child : it->children)
                         if (child) q.push_back(child);
               }
          }

          return depth;
     }
};

// RECURSIVE PRE-ORDER
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
     int maxDepth(Node* root) {
          if (!root) return 0;
          int depth{ 0 };

          // we can also use std::transform_reduce to get rid of loop
          for (const auto& child : root->children) depth = std::max(depth, maxDepth(child));
          return 1 + depth;
     }
};