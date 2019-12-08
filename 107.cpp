#include <vector>
#include <deque>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector< vector<int> > vv;
        TreeNode* p;
        deque<TreeNode*> q;
        if (root) q.push_front(root);
        int npv = q.size();
        vector<int> v;
        
        while (npv > 0) {
            for (int i=0; i<npv; ++i) {
                p = q.front();
                q.pop_front();
                v.push_back(p->val);
                if (p->left) q.push_back(p->left);
                if (p->right) q.push_back(p->right);
            }
            vv.push_back(v);
            v.clear();
            npv = q.size();
        }
        
        return vector< vector<int> >(vv.rbegin(), vv.rend());
    }
};