#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#ifdef DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

bool my_compare(const ListNode* a, const ListNode* b) {
  return b->val < a->val;
}

void print(vector<ListNode*> lists, int n) {
  cout << "n=" << n << '\n';
  for (int i=0; i<n; ++i) cout << lists[i]->val << ' ';
  cout << "\n\n";
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int n = lists.size();
      for (int i=0; i<n; ++i) {
        if (!lists[i]) {
          lists[i] = lists[n-1];
          --n;
          --i;
        }
      }

      if (!n) return NULL;
      if (n==1) return lists[0];
      
      make_heap(lists.begin(), lists.begin()+n, my_compare);

      ListNode head(-9999);
      ListNode *pp = &head;
      ListNode *p = NULL;

      while(n>1) {
        
        p = lists[0];
        pp->next = p;
        pp = p;

        pop_heap(lists.begin(), lists.begin()+n, my_compare);
        lists[n-1] = p->next;

        if (!lists[n-1]) {
          --n;
        }
        else {
          push_heap(lists.begin(), lists.begin()+n, my_compare);
        }
      }

      pp->next = lists[0];
      return head.next;
    }
};


#ifdef DEBUG

int main() {
  Solution s;

  ListNode a(1), b(4), c(5), d(1), e(3), f(4), g(2), h(6);

  a.next = &b;
  b.next = &c;
  d.next = &e;
  e.next = &f;
  g.next = &h;

  vector<ListNode*> v(3, 0);
  v[0] = &a;
  v[1] = &d;
  v[2] = &g;

  ListNode *p = s.mergeKLists(v);
  while (p) {
    cout << p->val << ' ';
    p = p->next;
  }
  cout << '\n';
}

#endif
