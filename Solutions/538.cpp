// 538. Convert BST to Greater Tree

#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY : O(N)


 // SAME AS QUESTION 1038

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {

		if (!root) return nullptr;

		std::vector<TreeNode*> stk{};
		auto it{ root };
		int sum{ 0 };
		while (!stk.empty() || it)
		{
			if (it)
			{
				stk.push_back(it);
				it = it->right;
			}
			else
			{
				it = stk.back(); stk.pop_back();
				sum += it->val;
				it->val = sum;

				it = it->left;
			}
		}
		return root;
	}
};


// RECURSIVE
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(H)

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {

		dfs(root);
		return root;
	}
private:
	
	int sum{ 0 };

	TreeNode* dfs(TreeNode* root)
	{
		if (!root) return nullptr;

		dfs(root->right);
		sum += root->val;
		root->val = sum;
		dfs(root->left);

		return root;
	}
};
