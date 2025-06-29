// 297. Serialize and Deserialize Binary Tree

#include <string>
#include <deque>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

#pragma GCC optimize("O3")

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 // TIME COMPLEXITY : O(n)
 // SPACE COMPLEXITY : O(n);
 
class Codec {
public:

     // Encodes a tree to a single string.
     std::string serialize(TreeNode* root)
     {
          if (!root) return "*";

          std::ostringstream oss{}; 
          std::deque<TreeNode*> q{};
          q.push_back(root);

          while (!q.empty())
          {
               const auto node{ q.front() };
               q.pop_front();

               if (node)
               {
                    oss << node->val;
                    q.push_back(node->left);
                    q.push_back(node->right);
               }
               else
               {
                    oss << '*';
               }
               
               oss << ',';
          }

          
          auto tree{ oss.str() };
          // trim trailing "*"
          tree.erase(std::find_if(rbegin(tree), rend(tree),
               [](char c) { return c != ',' && c != '*'; }).base(), end(tree));

          return tree;
     }

     // Decodes your encoded data to tree.
     TreeNode* deserialize(std::string data) {

          constexpr int nil{ -1111 }; // can act as null marker cuz , contraint [-1000,1000]
          auto stem{parse_tree(data)};


          if (stem.empty() || stem[0] == nil) return nullptr;

          // BUILD TREE
          auto root{ new TreeNode(stem[0]) };
          std::deque<TreeNode*> q{};
          q.push_back(root);

          int index{ 1 };
          
          while (!q.empty() && index<stem.size())
          {
               auto parent{ q.front() };
               q.pop_front();

               // Left child
               if (index < stem.size() && stem[index] != nil)
               {
                    parent->left = new TreeNode(stem[index]);
                    q.push_back(parent->left);
               }
               ++index;

               // Right child
               if (index < stem.size() && stem[index] != nil)
               {
                    parent->right = new TreeNode(stem[index]);
                    q.push_back(parent->right);
               }
               ++index;
          }
          return root;
     }

private:

     std::vector<int> parse_tree(const std::string& data, const int nil = -1111)
     {
          std::vector<int> tree{};
          tree.reserve(data.size() / 2);
          std::istringstream iss(data);
          std::string token{};

          while (std::getline(iss, token, ','))
          {
               if (token == "*")
                    tree.push_back(nil);
               else
                    tree.push_back(std::stoi(token));
          }

          return tree;
     }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
