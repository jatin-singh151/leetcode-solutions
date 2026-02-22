struct ListNode* reverseList(struct ListNode* head) {
    int*arr = (int*)malloc(5000*sizeof(int));
    struct ListNode* ptr = head;
    int i = 0;
    while (ptr != NULL) {
        arr[i] = ptr->val;
        ptr = ptr->next;
        i++;
    }
    i--;
    ptr = head;
    while (ptr != NULL) {
        ptr->val = arr[i];
        ptr = ptr->next;
        i--;
    }
    free(arr);
    return head;
}
