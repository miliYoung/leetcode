/**
 * 	LEETCODE 206. Reverse Linked List
 */

/**
 * Reverse a singly linked list.
 * 
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * Follow up:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if( NULL == head )
    {
        return NULL;
    }
    
    struct ListNode* node = NULL;
    struct ListNode* temp = NULL;

    while(head != NULL)
    {   
        temp = head->next;
        head->next = node;
        node = head;
        head = temp;
    }
    
    return node;
}