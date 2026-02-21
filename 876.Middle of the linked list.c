
struct ListNode* middleNode(struct ListNode* head) {
    int hops = 0;
    struct ListNode* fast = head;   
    struct ListNode* slow = head;
    while(fast){
        hops++;
        fast = fast->next;
        if(hops == 2){
            slow = slow->next;
            hops = 0;
        }
    }
    return slow;
}
