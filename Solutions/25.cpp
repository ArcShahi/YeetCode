// 25. Reverse Nodes in k-Group


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // TIME COMPLEXITY : O(N)
 // SPACE COMPLEXITY: O(1)

class Solution {
public:
     ListNode* reverseKGroup(ListNode* head, int k) {

          if (!head) return head;
          int n{ count_nodes(head) };
  
          ListNode dummy{ 0 };
          auto tail{ &dummy };

          auto start{ head };
          auto end{ next_node(start,k) };

          while (n>=k)
          {
               auto old_start{ start };
               tail->next = reverse_range(start, end);
               start = end;
               end = next_node(end, k);
               tail =old_start;
               n-=k;
          }
          tail->next = start;
          return dummy.next;
     }
private:
     // Moves node 'n' steps  ahead
     ListNode* next_node(ListNode* node, int n)
     {
          for (int i{ 0 }; i < n && node; ++i)
               node = node->next;
          return node;
     }

     int count_nodes(ListNode* head)
     {
          int count{ 0 };
          for (auto it{ head }; it; it = it->next) ++count;
          return count;
     }

     // Reverses nodes in rangel [ start, end-1 ] 
     ListNode* reverse_range(ListNode* start, ListNode* end)
     {
          ListNode* pvs{ nullptr };
          auto it{ start };
          while (it!=end)
          {
               auto succ{ it->next };
               it->next = pvs;
               pvs = it;
               it = succ;
          }
          return pvs;
     }
};