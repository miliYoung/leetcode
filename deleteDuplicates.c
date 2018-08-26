/**
 * LEETCODE 83. Remove Duplicates from Sorted List
 */

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * Example 1:
 * Input: 1->1->2
 * Output: 1->2
 * 
 * Example 2:
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
     
    if(head==NULL)
    {
        return head;
    }
    
    struct ListNode* p=head;
    struct ListNode* q=head->next;
    
    while(q!=NULL){
        if(q->val==p->val) {
            p->next = q->next;
        }else{
            p=q;
        }
        q = q->next;
    }
    
    return head;

}