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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode fatHead(-1);
    fatHead.next = head;

    ListNode *pp = &fatHead, *p = head;

    while(p) {
      if (p->next && p->val==p->next->val) {
        p = p->next;
        pp->next = p;
      }
      else {
        pp = p;
        p = p->next;
      }
    }
    return fatHead.next;
  }
};

#ifdef DEBUG

int main() {
  ListNode a(1), b(1), c(1), d(2);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  Solution s;
  ListNode *p = s.deleteDuplicates(&a);
  cout << p->val << ' ' << p->next->val << '\n';
}

#endif
