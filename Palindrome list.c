bool isPalindrome(struct ListNode* head)
{
    int array[100000],k=0;
    struct ListNode* temp=head;
    while(temp!=NULL)
    {
        array[k++]=temp->val;
        temp=temp->next;
    }
    for(int i=0;i<k/2;i++)
    {
        if(array[i]!=array[k-1-i])
            return false;
    }
    return true;
}
