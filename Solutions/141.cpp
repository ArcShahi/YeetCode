// 141. Linked List Cycle



  struct ListNode
  {
     int data{};
     ListNode* next{};

  };
    


  class Solution 
  {
  public:
       bool hasCycle(ListNode* head)
       {
            // No first or second Node
            if (!head || !head->next) return false;

            // Floyd's Linked List Cycle Finding Algorithm
            auto slow{ head };
            auto fast{ head };

            while (fast && fast->next)
            {
                 slow = slow->next;
                 fast = fast->next->next;

                 if (slow == fast) return true;
            }

            return false;
       }
  };