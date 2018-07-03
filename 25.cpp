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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head==NULL) return head;

    ListNode root(-9999);
    ListNode *pp=&root, *p=head;
    ListNode *tp, *tpp, *tmp;
    int c;
    while (p) {
      for (c=k, tp=p; tp&&c>0; --c) tp=tp->next;
      if (c) break;

      tpp = p;
      while(p!=tp) {
        tmp = p->next;
        p->next = pp->next;
        pp->next = p;
        p = tmp;
      }
      pp = tpp;
    }

    pp->next = p;
    return root.next;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  ListNode a(1), b(2), c(3), d(4), e(5), f(6);

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;

  ListNode *p = s.reverseKGroup(&a, 3);

  while(p) {
    cout << p->val << ' ';
    p = p->next;
  }
  cout << '\n';

}

#endif
