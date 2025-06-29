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

// Iterative DFS  PRE_ORDER
class Solution {
public:
     int maxDepth(Node* root) {

          if (not root) return 0;

          std::vector<std::pair<Node*, int>> stack{};
          stack.push_back({ root,1 });
          int max_depth{ 0 };

          while (!stack.empty())
          {
               const auto [node, depth] {stack.back()};
               stack.pop_back();

               max_depth = std::max(max_depth,depth);

               for (const auto& child : node->children)
                    if (child)
                         stack.push_back({ child,depth + 1 });

          }

          return max_depth;
     }
};
// BFS Iterative
class Solution {
public:
     int maxDepth(Node* root) {

          if (not root) return 0;
          std::deque<Node*> q{};
          q.push_back(root);
          int max_depth{ 0 };

          while (!q.empty())
          {
               auto width{ q.size() };

               while (width-->0)
               {
                    const auto itr{ q.front() };
                    q.pop_front();

                    // Push all children to queue
                    for (const auto& child : itr->children)
                         if (child)
                              q.push_back(child);
               }
               ++max_depth;
          }
          return max_depth;
     }
};