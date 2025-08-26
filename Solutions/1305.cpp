// 1305. All Elements in Two Binary Search Trees

#include <vector>
#include <algorithm>
#include <iterator>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 // TIME COMPLEXITY : O(N+M)
 // SPACE COMPLEXITY : O(N+M)

class Solution {
public:
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

	    auto x{ inorder_iterate(root1) };
	    auto y{ inorder_iterate(root2) };

	    stk.reserve(100);
	    std::vector<int> elements{};
	    elements.reserve(x.size() + y.size());
	    std::ranges::merge(x, y, std::back_inserter(elements));
	   
	    return elements;
	}
   
private:
	std::vector<int> inorder_iterate(TreeNode* root)
	{
		std::vector<int> nodes{};
		if (!root) return nodes;
		auto it{ root };

		while (!stk.empty() || it){
			if (it){
				stk.push_back(it);
				it = it->left;
			}
			else{
				it = stk.back();stk.pop_back();
				nodes.push_back(it->val);
				it = it->right;
			}
		}
		stk.clear();
		return nodes;
     }

private:
	std::vector<TreeNode*> stk{};
};



// I've yet to READ IT
// Solution by : https://leetcode.com/u/votrubac/ 
/* https://leetcode.com/problems/all-elements-in-two-binary-search-trees/solutions/464073/c-one-pass-traversal/?envType=problem-list-v2&envId=2bp25re7

void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
    while (n != nullptr)
	   s.push(exchange(n, n->left));
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    stack<TreeNode*> s1, s2;
    pushLeft(s1, root1);
    pushLeft(s2, root2);
    while (!s1.empty() || !s2.empty()) {
	   stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 :
		  s1.top()->val < s2.top()->val ? s1 : s2;
	   auto n = s.top(); s.pop();
	   res.push_back(n->val);
	   pushLeft(s, n->right);
    }
    return res;
}

*/