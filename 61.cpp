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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head;

    int n = 0;
    for(ListNode *ptr = head; ptr; ++n, ptr=ptr->next);

    k = k % n;
    if (!k) return head;
    
    ListNode fatHead(-1);
    fatHead.next = head;
    ListNode *pp = &fatHead, *p = head;

    for (int i=0; i<n-k; ++i) {
      pp = p;
      p = p->next;
    }

    pp->next = NULL;
    pp = p;
    while(pp->next) pp = pp->next;
    pp->next = fatHead.next;
    return p;
  }
};



#ifdef DEBUG

int main() {
  ListNode a(0), b(1), c(2);
  a.next = &b;
  b.next = &c;
  Solution s;
  ListNode *p = s.rotateRight(&a, 4);
  while (p) {
    cout << p->val << ' ';
    p = p->next;
  }
  cout << '\n';
}

#endif
