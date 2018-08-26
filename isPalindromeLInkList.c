/**
 * 	LEETCODE 234. Palindrome Linked List
 */

/**
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * Input: 1->2->2->1
 * Output: true
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return true;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    struct ListNode *secondHead = slow->next;
    slow->next = NULL;
    
    struct ListNode *p1 = secondHead;
    struct ListNode *p2 = p1->next;
    
    while(p1 != NULL && p2 != NULL)
    {
        struct ListNode *temp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = temp;
    }
    
    secondHead->next = NULL;
    
    struct ListNode *p = (p2 == NULL?p1:p2);
    struct ListNode *q = head;
    while(p != NULL)
    {
        if(p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    
    return true;

}