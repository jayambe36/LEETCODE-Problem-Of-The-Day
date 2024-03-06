class Solution {
public:
    bool hasCycle(ListNode *head) {
 ListNode * slow = head;
        ListNode * fast = head;
        while( fast != NULL)
        {
          
           if(fast->next==NULL || fast->next->next ==NULL) break;
              slow = slow->next;
              fast = fast->next->next;
             
             if(fast==slow)
             {
                 return true;
             }
        }
        return false;
    }
};
