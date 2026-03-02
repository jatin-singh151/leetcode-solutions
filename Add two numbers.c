struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *t1 = l1, *t2 = l2;
    struct ListNode *head=NULL, *t3=NULL;
    int sum=0;
    
    while(t1 || t2 || sum){
        if(t1){
            sum += t1->val;
            t1 = t1->next;
        }if(t2){
            sum += t2->val;
            t2 = t2->next;
        }
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->val = sum%10;
        sum /= 10;
        if(head){
            t3->next = new;
            t3 = new;
        }else
            head = t3 = new;
    }
    t3->next = NULL;
    return head;
}
