/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct node
 {
    int front,rear;
    struct TreeNode *arr[2000];
 }queue;
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
}
    int **result=malloc(2000*sizeof(int*));
    *returnColumnSizes=malloc(2000*sizeof(int));
(*returnSize)=0;
    queue q;
    q.front=0;
    q.rear=0;
    q.arr[q.rear++]=root;
    int count=0;
    while(q.front<q.rear)
    {
        int levelsize=q.rear-q.front;
        result[*returnSize]=malloc(levelsize*sizeof(int));
        (*returnColumnSizes)[*returnSize]=levelsize;
        for(int i=0;i<levelsize;i++)
        {
            struct TreeNode *temp=q.arr[q.front++];
           result[*returnSize][i]=temp->val;
            if(temp->left!=NULL)q.arr[q.rear++]=temp->left;
            if(temp->right!=NULL)q.arr[q.rear++]=temp->right;
        }
        if(count%2!=0)
        {
            int last=levelsize-1;
            for(int i=0;i<last;i++)
            {
                int temp=result[*returnSize][i];
                result[*returnSize][i]=result[*returnSize][last];
                result[*returnSize][last]=temp;

                last--;
            }
        }
        (*returnSize)++;
        count++;
    }
    return result;
}
