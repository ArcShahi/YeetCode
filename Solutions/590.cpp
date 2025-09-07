// 590. N-ary Tree Postorder Traversal

#include <vector>
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


// RECURSIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(N)

class Solution {
public:
     std::vector<int> postorder(Node* root) {

          dfs(root);
          return vec;
     }

     std::vector<int> vec{};

     void dfs(Node* node)
     {
          if (!node) return;
          // Process children then node
          for (const auto& child : node->children)
               dfs(child);

          vec.push_back(node->val);
     }
};

// ITERATIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPELXITY : O(N)

class Solution {
public:
     std::vector<int> postorder(Node* root) {

          std::vector<int> vec{};
          if (!root) return vec;

          std::vector<Node*> stk{root};
          std::deque<int> q{};

          while (!stk.empty())
          {
               const auto it{ stk.back() }; stk.pop_back();

               // Root first , then child ( cuz stack so order reverses )
               q.push_front(it->val); // no need to reverse later

               for (const auto& child : it->children)
                    if (child) stk.push_back(child);
          }

          return std::vector(begin(q), end(q)); 
     }

};