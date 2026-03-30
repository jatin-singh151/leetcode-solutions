/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *addNode(int *inorder, int *preorder, int size)
{
    if (size == 0)
        return NULL;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int i = 0;
    while (inorder[i] != preorder[0])
        i++;
    root->left = addNode(inorder, preorder + 1, i);
    root->right = addNode(inorder + i + 1, preorder + i + 1, size - i - 1);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return addNode(inorder, preorder, inorderSize);
}
