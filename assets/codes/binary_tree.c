/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxSum;

int maxPathSum(struct TreeNode* root) {
    maxSum = INT_MIN;
    if (root == NULL) return 0;
    maxSum = root->val;
    helper(root);
    return maxSum;
}

int helper(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    int left = max(0, helper(root->left));
    int right = max(0, helper(root->right));
    int sum = root->val + left + right;
    maxSum = max(maxSum, sum);
    
    return max(left, right) + root->val;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}