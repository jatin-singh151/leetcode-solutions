struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while (fast!=NULL&&fast->next!=NULL) 
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) 
        {
            struct ListNode* start=head;
            while (start!=slow) 
            {
                start=start->next;
                slow=slow->next;
            }
            return start;  // Cycle start point
        }
    }
    return NULL;  // No cycle
}
