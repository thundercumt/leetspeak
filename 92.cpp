class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pp = &dummy;
        
        for (int i=1; i<m; ++i) {
            pp = pp -> next;
        }
        
        
        ListNode *pi = pp -> next;
        ListNode *pj = pi -> next;
        ListNode *pt;

        for (int i=m; i<n; ++i) {
            pt = pj -> next;
            pj->next = pi;            
            pi = pj;
            pj = pt;          
        }
        
        
        pp->next->next = pj;
        pp->next = pi;
        
        return dummy.next;
    }
};