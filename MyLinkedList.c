/**
 * LEETCODE 707. Design Linked List
 */

/**
 * Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. 
 * A node in a singly linked list should have two attributes: val and next. val is the value of the current node,
 *  and next is a pointer/reference to the next node. If you want to use the doubly linked list, 
 *  you will need one more attribute prev to indicate the previous node in the linked list. 
 *  Assume all nodes in the linked list are 0-indexed.
 *  
 *  Implement these functions in your linked list class:
 *  get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
 *  addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 *  addAtTail(val) : Append a node of value val to the last element of the linked list.
 *  addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
 *  deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 *  
 *  Example:
 *  MyLinkedList linkedList = new MyLinkedList();
 *  linkedList.addAtHead(1);
 *  linkedList.addAtTail(3);
 *  linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 *  linkedList.get(1);            // returns 2
 *  linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 *  linkedList.get(1);            // returns 3
 *  
 *  Note:
 *  All values will be in the range of [1, 1000].
 *  The number of operations will be in the range of [1, 1000].
 *  Please do not use the built-in LinkedList library.
 */

typedef struct {
    int val;
    struct ListNode* next;
}ListNode;

typedef struct {
    struct ListNode* head;
    int size;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    struct MyLinkedList* pList = malloc(sizeof(MyLinkedList));
    if(pList != NULL)
    {
       memset(pList, 0, sizeof(MyLinkedList));
    }
    
    return pList;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(NULL == obj || index > obj->size)
    {
        return -1;
    }
    
    int i = 0;
	int res = -1;
    struct ListNode* pNode = obj->head;
	if(index == 0)
	{
		if(pNode != NULL)
		{
			return pNode->val;
		}
	}
	
    for(i = 0; i < index; i++)
    {
		if(pNode != NULL)
        {
			pNode = pNode->next;
		}
    }
	
	if(pNode != NULL)
    {
		res =  pNode->val;
	}
	
	return res;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(NULL == obj)
    {
        return ;
    }
    
    ListNode* pNode = malloc(sizeof(ListNode));
    if(NULL != pNode)
    {
        pNode->val = val;
        pNode->next = NULL;
    }
    else
    {
        return ;
    }
    
    pNode->next = obj->head;
    obj->head = pNode;
    obj->size++;

    return ;   
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	
	if(NULL == obj)
    {
        return ;    
    }
    
    ListNode* pNode = malloc(sizeof(ListNode));
    if(NULL != pNode)
    {
        pNode->val = val;
        pNode->next = NULL;
    }
    else
    {
        return ;
    }
    
    if(obj->size == 0)
    {
        myLinkedListAddAtHead(obj,val);
    }
    
    ListNode* curNode = obj->head;
    while(curNode && curNode->next)
    {
        curNode = curNode->next;
    }
   
    curNode->next = pNode;
    obj->size++;
	
    return ;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
	if( NULL == obj || index > obj->size)
    {
        return ;
    }
	
	if(index == 0)
	{
		myLinkedListAddAtHead(obj, val);
		return ;
	}
    
    ListNode* pNode = malloc(sizeof(ListNode));
    if(NULL != pNode)
    {
        pNode->val = val;
        pNode->next = NULL;
    }
    else
    {
        return ;
    }
    
    int i = 0;
    ListNode* curNode = obj->head;
    for(i = 1; i < index; ++i)
    {
        if(curNode != NULL)
        {
            curNode = curNode->next;
        }
    }
    
    if(curNode != NULL)
    {
        pNode->next = curNode->next;
        curNode->next = pNode;
        obj->size++;
    }
    
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if( NULL == obj || index > obj->size)
    {
        return ;
    }
    
    if(index == 0)
    {
        if(NULL != obj->head)
        {
            obj->head = obj->head->next;
        }
        return ;
    }
	
    int i = 0;
    ListNode* curNode = obj->head;
    for(i = 1; i < index; ++i)
    {
        if(curNode != NULL)
        {
            curNode = curNode->next;
        }
    }
    
     if(curNode != NULL && curNode->next != NULL)
     {
        ListNode* temp = curNode->next;
        curNode->next = curNode->next->next;
        free(temp);
        obj->size--;
     }
    
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    if(NULL == obj)
    {
        return ;
    }
    
    ListNode* curNode = obj->head;
    ListNode* temp;
    while(curNode)
    {
       temp = curNode;
       curNode = curNode->next;
       free(temp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */