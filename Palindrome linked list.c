/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int len=-1;
    struct ListNode* curr=head;
    for(len=0;curr!=NULL;len++){
        curr=curr->next;
    }
    int nums[len];
    for(int i=0;i<len;i++){
        nums[i]=head->val;
        head=head->next;
    }
    for(int l=0,r=len-1;l<r;l++,r--){
        if(nums[l]!=nums[r]){
            return false;
        }
    }
    return true;
}
