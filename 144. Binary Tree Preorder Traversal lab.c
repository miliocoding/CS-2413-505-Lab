/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorderTraversalHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    result[(*returnSize)++] = root->val; 
    preorderTraversalHelper(root->left, result, returnSize); 
    preorderTraversalHelper(root->right, result, returnSize); 
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); 
    if (result == NULL) {
        return NULL;
    }
    preorderTraversalHelper(root, result, returnSize);
    return result;
}
