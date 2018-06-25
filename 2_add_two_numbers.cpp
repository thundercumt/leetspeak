#include <cstdio>

#ifdef DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int r = 0;
      int t;
      ListNode n(0);
      ListNode *p = &n;

      while (l1 != NULL || l2 != NULL || r != 0) {
        t = 0;
        if (l1) t += l1->val;
        if (l2) t += l2->val;
        t += r;

        r = t / 10;
        t = t % 10;

        p->next = new ListNode(t);
        p = p->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      return n.next;
    }
};


#ifdef DEBUG

void print(ListNode *p) {
  while(p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main() {
  ListNode *a = new ListNode(3);
  ListNode *b = new ListNode(9);
  b->next = new ListNode(9);
  b->next->next = new ListNode(9);
  b->next->next->next = new ListNode(9);
  ListNode *c = Solution().addTwoNumbers(a, b);
  print(c);
}

#endif
