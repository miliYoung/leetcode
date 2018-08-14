/**
 * LEETCODE 821. Shortest Distance to a Character
 */

/**
 * Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
 * Example 1:
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * Note:
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize) {
    if(NULL == S)
    {
        return NULL;
    }
    
    int len = strlen(S);
    int* res = malloc(sizeof(int)*len);
    int i = 0;
    bool bflag = false;
    if(res != NULL)
    {
        memset(res, 0, sizeof(int)*len);
    }
    else
    {
        return res;
    }
    
    
    for( i = 0 ; i < len; ++i)
    {
        res[i] = len;
    }
    
    for( i = 0 ; i < len; ++i)
    {
        if(S[i] == C)
        {
            res[i] = 0;
            bflag = true;
        }
        else if(i > 0)
        {
            res[i] = res[i - 1] + 1;
        }
    }
    
    for(i = len - 2; i >=0; --i)
    {
        res[i] = res[i] < (res[i+1] + 1) ? res[i] : (res[i+1] + 1); 
    }
    
    if(bflag)
    {
        *returnSize = len;
    }
    else
    {
        *returnSize = 0;
    }
    
    
    return res;
    
}