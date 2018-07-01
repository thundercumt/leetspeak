#include <iostream>

using namespace std;

#ifdef DEBUG
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == NULL) return NULL;
      if (n<=0) return head;

      ListNode fatHead(-1);
      fatHead.next = head;
      
      ListNode *l=&fatHead, *r=head;
      int i;
      for(i=1; i<n && r; ++i) r=r->next;

      if (i<n) return head;

      while(r->next) {
        r = r->next;
        l = l->next;
      }

      l->next = l->next->next;
      return fatHead.next;
    }
};


#ifdef DEBUG

int main() {
  ListNode head(-1), one(1), two(2), three(3), four(4), five(5);
  four.next = &five;
  three.next = &four;
  two.next = &three;
  one.next = &two;
  head.next = &one;

  Solution s;
  s.removeNthFromEnd(&head, 2);

  ListNode *p = &head;
  while(p) {
    cout << p->val << ' ';
    p = p->next;
  }
  cout << '\n';
}

#endif
