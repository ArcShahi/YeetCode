// 1038. Binary Search Tree to Greater Sum Tree

#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
	TreeNode* bstToGst(TreeNode* root) {

		if (!root) return;

		std::vector<TreeNode*> stk{};
		auto it{ root };
		int sum{ 0 };
		while (!stk.empty() || it)
		{
			if (it)
			{
				stk.push_back(it);
				it = it->right;;
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
	TreeNode* bstToGst(TreeNode* root) {

		int sum{ 0 };
		dfs(root, sum);
		return root;
	}
private:
	
	TreeNode* dfs(TreeNode* root, int& sum)
	{
		if (!root) return nullptr;

		dfs(root->right,sum);
		sum += root->val;
		root->val = sum;
		dfs(root->left,sum);

		return root;
	}
};