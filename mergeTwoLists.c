/**
 * 	LEETCODE 21. Merge Two Sorted Lists
 */

/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    struct ListNode* node = NULL;
    struct ListNode* res = NULL;
    node =  (struct ListNode*)malloc(sizeof(struct ListNode));
    res = node;
    
    while(l1 != NULL && l2 != NULL)
    {
        if( l1->val <= l2->val )
        {
             node->next = l1;
             l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    
    while(l1 != NULL)
    {
        node->next = l1;
        l1 = l1->next;
        node = node->next;
    }
    
    while(l2 != NULL)
    {
        node->next = l2;
        l2 = l2->next;
        node = node->next;
    }
    
    return res->next;
}