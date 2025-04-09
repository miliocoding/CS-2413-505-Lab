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
    result[(*returnSize)++] = root->val; // Add the current node value
    preorderTraversalHelper(root->left, result, returnSize); // Traverse the left subtree
    preorderTraversalHelper(root->right, result, returnSize); // Traverse the right subtree
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); // Allocate memory for result array
    if (result == NULL) {
        return NULL; // Handle allocation failure
    }
    preorderTraversalHelper(root, result, returnSize);
    return result;
}
