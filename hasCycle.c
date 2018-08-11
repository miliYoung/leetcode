/**
 * LEETCODE 141. Linked List Cycle
 */

/**
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
   
        if(head == NULL)
    	{
    		return false;
    	}
 
    	struct ListNode *fast = head;
    	struct ListNode *slow = head;
 
    	while(fast->next != NULL)
    	{
    		fast = fast->next->next;
 
    		if(fast == NULL)
    		{
    			return false;
    		}
 
    		slow = slow->next;
 
    		if(fast == slow)
    		{
    			return true;
    		}
    	}
 
    	return false;
}