struct ListNode* reverseList(struct ListNode* head, int* Len) {
    struct ListNode* prev = NULL;

    while (head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        (*Len)++;
    }

    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = 0, len2 = 0;
    l1 = reverseList(l1, &len1);
    l2 = reverseList(l2, &len2);

    int length = (len1 < len2) ? len1 : len2; // Smallest length among 2 Linked List

    struct ListNode* large = (len1 < len2) ? l2 : l1; // Largest Linked List
    struct ListNode* small = (len1 < len2) ? l1 : l2; // Smallest Linked List
    struct ListNode* return_ptr = large; // return Largest Linked List

    int carry = 0;
    for (int i = 0; i < length; i++) {
        int val = large->val + small->val + carry;
        large->val = val % 10;
        carry = val / 10;
        large = large->next;
        small = small->next;
    }

    while (large) {
        int val = large->val + carry;
        large->val = val % 10;
        carry = val / 10;
        large = large->next;
    }

    if (carry) {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;

        struct ListNode* temp = return_ptr;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return reverseList(return_ptr, &len1);
}
