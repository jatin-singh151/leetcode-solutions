
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode *l,*s,*t;
    if(head==NULL)return NULL; 

    if(head->next==NULL)
    {
        if(head->val==val)
        {
            free(head);
            return NULL;
        }

        else
        {
            return head;
        }
    }

    s=head;   

    while(s!=NULL)
    {
    
        if(s->val==val)
        {
            l=s;
            s=s->next;
            free(l);
            head=s;
        }
        else if(s->next!=NULL && s->next->val==val)
        {
           l=s->next;
           s->next=l->next;
           free(l);

        }
        else
        {
            s=s->next;
        } 

    }

    return head;
}
