// 1669. Merge In Between Linked Lists


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
 public:
      ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
           
           auto start{ list1 };
           for (int i{ 1 }; i < a; ++i)
                start = start->next;

           auto last{ start };
           for (int i{ 0 }; i <= b - a + 1; ++i)
                last = last->next;

           start->next = list2;

           auto tail{ list2 };
           while (tail->next)
                tail = tail->next;

           tail->next = last;

           return list1;
      }
 };
