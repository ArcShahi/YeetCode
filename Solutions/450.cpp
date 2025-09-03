// 450. Delete Node in a BST

#include <utility>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // RECURSIVE 
 // TIME COMPLEXITY : O(H)
 // SPACE COMPLEXITY: O(H) : stack usage


 class Solution {
 public:
      TreeNode* deleteNode(TreeNode* root, int key) {
           if (!root) return nullptr;

           if (key < root->val) 
           {
                root->left = deleteNode(root->left, key);
           }
           else if (key > root->val)
           {
                root->right = deleteNode(root->right, key);
           }
           else 
           {
                // Found the node to delete
                if (!root->left) 
                {
                     return root->right;
                }
                else if (!root->right) 
                {
                     return root->left;
                }
                else 
                {
                     // Node has two children
                     // Find inorder successor (smallest in right subtree)
                     auto min = find_min(root->right);

                     // Copy the successor's value to this node
                     root->val = min->val;

                     // Delete the successor
                     root->right = deleteNode(root->right, min->val);
                }
           }
           return root;
      }

 private:
      TreeNode* find_min(TreeNode* node) {
           while (node->left)node = node->left;
           return node;
      }
 };

 // TIME COMPLEXITY : O(H)
 // SPACE COMPLEXITY: O(1)

 class Solution2 {
 public:
      TreeNode* deleteNode(TreeNode* root, int key) {
           if (!root) return nullptr;

           TreeNode dummy{ 0 };
           dummy.left = root;

           // Find the node and it's parent
           auto it{ root };
           TreeNode* parent{ &dummy };

           while (it && it->val!=key)
           {
                parent = it;
                it = key < it->val ? it->left : it->right;
           }

           // Key not found
           if (!it) return root;

           int children{ count_child(it) };

           if (children == 0) {
                replace_child(parent, it, nullptr);
           }
           else if (children == 1) {
                auto child = it->left ? it->left : it->right;
                replace_child(parent, it, child);
           }
           else 
           {
                // Node has two children
                auto succ = find_min(it->right);
                TreeNode* succ_parent = find_parent(it, succ->val);

                it->val = succ->val;
                replace_child(succ_parent, succ, succ->right);
           }

           return dummy.left;
      }
 private:
      int count_child(TreeNode* node) {
           int count = 0;
           if (node->left) count++;
           if (node->right) count++;
           return count;
      }

      TreeNode* find_min(TreeNode* node) {
           while (node->left)node = node->left;
           return node;
      }

      TreeNode* find_parent(TreeNode* root,int key)
      {
           TreeNode* parent{ root };

           auto it = key < root->val ? root->left : root->right;

           while (it && it->val!=key)
           {
                parent = it;
                it = key < it->val ? it->left : it->right;
           }

           return parent;
      }

      void replace_child(TreeNode* parent, TreeNode* old_child, TreeNode* new_child) {
           if (parent->left == old_child) parent->left = new_child;
           else parent->right = new_child;
      }
      
 };

