/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *cloneGraph(struct Node *s) {
    if(s == NULL) return NULL;
	struct Node* nodes[101] = {0};
    struct Node* q[101];
    nodes[s->val] = malloc(sizeof(struct Node));
    nodes[s->val]->val = s->val;
    nodes[s->val]->numNeighbors = s->numNeighbors;
    nodes[s->val]->neighbors = malloc(s->numNeighbors * sizeof(struct Node*));
    int front = 0, back = 0;
    q[back++] = s;
    while(q[front] != NULL){
        struct Node* curr = q[front++];
        struct Node* clone = nodes[curr->val];
        int nig = clone->numNeighbors;
        for(int i = 0; i < nig; i++){
            struct Node* n = curr->neighbors[i];
            if(nodes[n->val] == NULL){
                nodes[n->val] = malloc(sizeof(struct Node));
                nodes[n->val]->val = n->val;
                nodes[n->val]->numNeighbors = n->numNeighbors;
                nodes[n->val]->neighbors = malloc(n->numNeighbors * sizeof(struct Node*));
                q[back++] = n;
            }
            clone->neighbors[i] = nodes[n->val];
        }
    }
    return nodes[s->val];

}
