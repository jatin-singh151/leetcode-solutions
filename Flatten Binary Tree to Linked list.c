/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode* current = root;

    while (current != NULL) {
        if (current->left) {
            struct TreeNode* temp = current->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
