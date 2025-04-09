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
void inorderTraversalHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    inorderTraversalHelper(root->left, result, returnSize); // Traverse the left subtree
    result[(*returnSize)++] = root->val; // Add the current node value
    inorderTraversalHelper(root->right, result, returnSize); // Traverse the right subtree
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int)); // Allocate memory for result array
    if (result == NULL) {
        return NULL; // Handle allocation failure
    }
    inorderTraversalHelper(root, result, returnSize);
    return result;
}
