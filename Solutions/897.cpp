// 897. Increasing Order Search Tree

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
	TreeNode* increasingBST(TreeNode* root) {

		TreeNode dummy{};
		auto tail{ &dummy };

		std::vector<TreeNode*> stk{};
		auto it{ root };

		while (!stk.empty() || it)
		{
			if (it)
			{
				stk.push_back(it);
				it = it->left;
			}
			else
			{
				it = stk.back();  stk.pop_back();

				tail->right = it;
				tail = tail->right;
				tail->left = nullptr;

				it = it->right;
			}
		}

		return dummy.right;

	}
};

