// 109. Convert Sorted List to Binary Search Tree


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
  
// TIME COMPLEXITY : O(NlogN)
// SPACE COMPLEXITY : O(logN)

class Solution {
public:
     TreeNode* sortedListToBST(ListNode* head) {

          return plant_tree(head);
     }

     ListNode* middle(ListNode* begin,ListNode* end=nullptr)
     {
          auto slow{ begin };
          for (auto fast{ begin }; fast!=end && fast->next!=end; fast = fast->next->next)
               slow = slow->next;

          return slow;
     }

     TreeNode*  plant_tree( ListNode* start,ListNode* end=nullptr)
     {
          if (start == end) return;
        
          auto mid{ middle(start,end) };
          auto root{ new TreeNode(mid->val) };
          
          root->left = plant_tree(start, mid);
          root->right = plant_tree(mid->next, end);

          return root;
     }

};