/**
 * 	LEETCODE 20. Valid Parentheses
 */

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 *  determine if the input string is valid.
 *  
 *  An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 *  Note that an empty string is also considered valid.
 *  
 *  Example 1:
 *  Input: "()"
 *  Output: true
 *  Example 2:
 *  
 *  Input: "()[]{}"
 *  Output: true
 *  Example 3:
 *  
 *  Input: "(]"
 *  Output: false
 *  Example 4:
 *  
 *  Input: "([)]"
 *  Output: false
 *  
 *  Example 5:
 *  Input: "{[]}"
 *  Output: true
 */

bool isMatch(char c1, char c2)
{
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '{' && c2 == '}') return true;
    if(c1 == '[' && c2 == ']') return true;
    
    return false;
}

bool isValid(char* s) 
{
	if(NULL == s)
	{
		return false;
	}	

	int top = -1;
	int i = 0;
	for(i = 0; i < strlen(s); ++i)
	{
		if(top < 0 || !isMatch(*(s+top),*(s+i)))
		{
			top++;
			*(s+top) = *(s+i);
		}
		else
		{
			top--;
		}
	}    

	return top == -1;
}