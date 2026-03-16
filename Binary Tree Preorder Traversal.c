int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void helper(struct TreeNode* root, int* answer, int* top)
{
    if (root == NULL) return;
    answer[(*top)++] = root->val; // visit the current node
    helper(root->left, answer, top); // recursively visit left subtree
    helper(root->right, answer, top); // recursively visit right subtree
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int *answer = malloc(*returnSize * sizeof(int));
    int top = 0;
    int *topptr = &top;
    helper(root, answer, topptr);
    return answer;
}
