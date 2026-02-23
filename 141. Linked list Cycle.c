bool hasCycle(struct ListNode *head) {
    if(!head || !head->next) return false;
    struct ListNode *ptr = head;
    while(ptr->next){
        if(ptr->val == INT_MAX) return true;
        ptr->val = INT_MAX;
        ptr = ptr->next;
    }
    return false;
}
