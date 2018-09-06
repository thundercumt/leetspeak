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
    ListNode* partition(ListNode* head, int x) {
      ListNode lt(-1), ge(-1);
      ListNode *pp1 = &lt, *pp2 = &ge;
      ListNode *p = head;

      while(p) {
	if (p->val < x) {
	  pp1->next = p;
	  pp1 = p;
	}
	else {
	  pp2->next = p;
	  pp2 = p;
	}
	p = p->next;
      }

      pp2->next = NULL;
      pp1->next = ge.next;
      return lt.next;
    }
};


#ifdef DEBUG

int main() {
  ListNode a(1), b(4), c(3), d(2), e(5), f(2);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;

  Solution s;
  ListNode* p = s.partition(&a, 3);

  while(p) {
    cout << p->val << ' ';
    p = p->next;
  }
}

#endif
