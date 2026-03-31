/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* NewNode(int val) {
    struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->left = new->right = NULL;
    new->val = val;
    return new;
}

int findInd(int* arr, int size, int val) {
    int ind;
    for (ind = 0; ind < size; ind++) {
        if(arr[ind] == val) break;
    }
    return ind;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postSize) {
   int val = postorder[postSize-1];
   struct TreeNode* node = NewNode(val);
   int idx = findInd(inorder,inorderSize,val);
   if(inorderSize - idx - 1) {
    int rightSubtreeSize = inorderSize - idx - 1;
    node->right = buildTree(inorder + idx + 1, inorderSize - idx - 1, postorder + idx,inorderSize - idx - 1);
   }
   if(idx) {
    int leftSubtreeSize = idx;
    node->left = buildTree(inorder, leftSubtreeSize, postorder, leftSubtreeSize);
    }
    return node;
}
