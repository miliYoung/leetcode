/**
 * LEETCODE 633. Sum of Square Numbers
 */

/**
 * Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
 * 
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * Example 2:
 * Input: 3
 * Output: False
 */

bool judgeSquareSum(int c) {
    if(c < 0)
    {
        return false;
    }
    
    int num = sqrt(c)+1;
    
    int low = 0;
    int high = num;
    while(low <= high)
    {
        if(low * low + high *high == c)
        {
            return true;
        }
        else if(low * low + high *high < c)
        {
            low = low + 1;
        }
        else if(low * low + high * high > c)
        {
            high = high - 1;
        }
    }
    
    return false;
    
}