#include <iostream>

using namespace std;

#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == NULL && l2 == NULL) return NULL;
      if (l1 == NULL) return l2;
      if (l2 == NULL) return l1;

      ListNode n(-99999);
      ListNode *p1=l1, *p2=l2;

      ListNode *pp = &n;
      ListNode *p;
      while (p1 && p2) {
        if (p1->val < p2->val) {
          p = p1;
          p1 = p1->next;
          p->next = NULL;
        }
        else {
          p = p2;
          p2 = p2->next;
          p->next = NULL;
        }
        pp->next = p;
        pp = p;
      }

      if (p1 == NULL) pp->next = p2;
      else pp->next = p1;

      return n.next;
    }
};


#ifdef DEBUG

int main() {
  Solution s;

  ListNode a(1), b(1), c(2), d(3), e(4), f(4);
  a.next = &c;
  c.next = &e;
  b.next = &d;
  d.next = &f;

  ListNode *p = s.mergeTwoLists(&a, &b);

  while(p) {
    cout << p->val << ' ';
    p = p->next;
  }
  cout << '\n';
}

#endif
