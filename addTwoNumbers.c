/**
 * 	LEETCODE 2. Add Two Numbers
 */

/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    ListNode* sum = NULL;
    ListNode* res = NULL;
    ListNode* temp = NULL;
    int extra = 0;
        
    while(NULL != l1 && NULL != l2)
    {   
        if(l1->val + l2->val + extra >= 10)
        {
            sum = new ListNode(l1->val + l2->val + extra - 10);
            extra = 1;
        }
        else
       	{
            sum = new ListNode(l1->val + l2->val + extra);
            extra = 0;
        }
            
        if( NULL == res )
        {
            res = temp = sum;
        }
        else
        {
            temp->next = sum;
            temp = sum;
        }
        
        l1 = l1->next;
        l2 = l2->next;
    }
        
    while(NULL != l1)
    {
        if(l1->val + extra >= 10)
        {
            sum = new ListNode(l1->val + extra - 10);
            extra = 1;
        }
        else
        {
            sum = new ListNode(l1->val + extra);
            extra = 0;
        }
            
        l1 = l1->next;
        temp->next = sum;
        temp = sum;
    }
        
    while(NULL != l2)
    {
        if(l2->val + extra >= 10)
        {
            sum = new ListNode(l2->val + extra - 10);
            extra = 1;
        }
        else
        {
            sum = new ListNode(l2->val + extra);
            extra = 0;
        }
        
        l2 = l2->next;
        temp->next = sum;
        temp = sum;
    }
        
        
    if(extra > 0)
    {
         sum = new ListNode(extra);
         temp->next = sum;
    }
        
        
    return res;
}