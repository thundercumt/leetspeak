#include <cstddef>
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        findMaxDepth(root, 1);
        return maxLevel;
    }

private:
    void findMaxDepth(TreeNode* p, int level) {
        maxLevel = max(maxLevel, level);
        if (p->left) findMaxDepth(p->left, level+1);
        if (p->right) findMaxDepth(p->right, level+1);
    }
    
    int maxLevel = 0;
};