#include <vector>
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
  ListNode* swapPairs(ListNode* head) {
    if (head==NULL || head->next==NULL) return head;

    ListNode r(-9999);
    ListNode *pp = &r;
    ListNode *p1 = head, *p2 = head->next;
    ListNode *t;
    
    while(p1 && p2) {
      t = p2->next;
      pp->next = p2;
      p2->next = p1;
      pp = p1;
      p1 = t;
      p2 = NULL;
      if (p1) p2 = p1->next; 
    }

    pp->next = p1;
    return r.next;
  }
};


#ifdef DEBUG

int main() {
  ListNode a(1), b(2), c(3), d(4);
  a.next = &b;
  b.next = &c;

  Solution s;
  ListNode* p = s.swapPairs(&a);

  while(p) {
    cout << p->val << ' ';
    p = p->next;
  }
  cout << '\n';
}

#endif
