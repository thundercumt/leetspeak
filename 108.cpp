#include <cstddef>
#include <vector>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (end < start) return NULL;
        int pivotal = start + (end - start) / 2;
        TreeNode *p = new TreeNode(nums[pivotal]);
        p->left = sortedArrayToBST(nums, start, pivotal-1);
        p->right = sortedArrayToBST(nums, pivotal+1, end);
        return p;
    }
};