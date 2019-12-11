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
    bool isBalanced(TreeNode* root) {
        int ht = 0;
        return isBalanced(root, ht);
    }
private:
    bool isBalanced(TreeNode* p, int& ht) {
        if (!p) {
            ht = 0;
            return true;
        }
        int hl=0, hr=0;
        bool bl = isBalanced(p->left, hl);
        if (!bl) return false;
        bool br = isBalanced(p->right, hr);
        if (!br) return false;
        if ((hl-hr) < -1 || (hl-hr) > 1) return false;
        ht = max(hl, hr) + 1;
        return true;
    }
};