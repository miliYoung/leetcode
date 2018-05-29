/**
 * 		LEETCODE 155. Min Stack
 */

/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */


typedef struct Stack
{
    int data;
    struct Stack *next;
    int Size;
}MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) 
{
    MinStack *stack=(MinStack *)malloc(sizeof(MinStack ));
    stack->Size=0;
    stack->next=NULL;
    stack->data=NULL;
    return stack;
}

void minStackPush(MinStack* obj, int x) 
{
    MinStack *node=(MinStack *)malloc(sizeof(MinStack));
    node->data=x;
    node->next=obj->next;
    obj->next=node;
    obj->Size++;
}

void minStackPop(MinStack* obj) 
{
    if(obj->Size)
    {
        MinStack *p=obj->next;
        obj->next=p->next;
        obj->Size--;
        free(p);
    }
}
int Min(int a,int b)
{
    return a<b?a:b;
}
int minStackTop(MinStack* obj) 
{
    return obj->next->data;
}

int minStackGetMin(MinStack* obj)
{
    if(obj->Size==0)
    {
        return NULL;
    }
    else
    {
        int min=obj->next->data;
        MinStack *p=obj->next;
        while(p!=NULL)
        {
            min=Min(min,p->data);
            p=p->next;
        }
        return min;
    }
    return NULL;
}

void minStackFree(MinStack* obj) 
{
    if(obj->Size)
    {
        minStackPop(obj);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

