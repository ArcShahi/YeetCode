// 589. N-ary Tree Preorder Traversal

#include <vector>

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

// ITERATIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
     std::vector<int> preorder(Node* root) {

          std::vector<int> vec{};

          if (!root) return vec;

          std::vector<Node*> stk{};
          stk.push_back(root);

          while (!stk.empty())
          {
               const auto it{ stk.back() }; stk.pop_back();
               vec.push_back(it->val);

               for (int i = it->children.size()-1; i >= 0; --i)
                    if (it->children[i]) stk.push_back(it->children[i]);
          }
          return vec;
     }
};


// RECURSIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)

class Solution {
public:
     std::vector<int> preorder(Node* root) {

          dfs(root);
          return vec; 
     }
private:
     std::vector<int> vec{};

     void dfs(Node* node)
     {
          if (!node) return;

          // Process node then child
          vec.push_back(node->val);

          for (const auto& child : node->children)
               preorder(child);
     }
};