/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int status(struct TreeNode* root, int* n){
    //Return value - Description
    //0 - node don't have camera(0) and is not being watched(0) total 0.
    //1 - node don't have camera(0) and is being watched(1) total 1.
    //2 - node has camera(1) and is being watched(1) total 2.
    if(root == NULL){
        return 1;
    }

    int l_status = status(root->left, n);
    int r_status = status(root->right, n);

    if(l_status == 0 || r_status == 0){
        *n += 1;
        return 2;
    }

    if(l_status == 2 || r_status == 2){
        return 1;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root){
    int* n = calloc(1, sizeof(int));
    if(status(root, n) == 0){
        *n += 1;
    }

    return *n;
}
