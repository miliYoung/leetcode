/**
 * 	LEETCODE 203. Remove Linked List Elements
 */

/**
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    if( NULL == head )
    {
        return NULL;
    }
    
    struct ListNode* pNode = head;
    struct ListNode* temp  = NULL;
    while(pNode != NULL && pNode->val == val )
    {
        pNode = pNode->next;
    }
    
    temp = pNode;
    
    while(pNode != NULL && pNode->next != NULL)
    {
        if(pNode->next->val == val)
        {
            pNode->next = pNode->next->next;
        }
        else
        {
            pNode = pNode->next;
        }
    }
   
    return temp;
}