/**
 * 	LEETCODE 9. Palindrome Number
 */

/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 * 
 * Example 1:
 * Input: 121
 * Output: true
 * 
 * Example 2:
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */

/**
 * [isPalindrome description] 判断一个数字是否是回文数
 * @param  x [description] 待判断的数字
 * @return   [description] 返回true表示是，返回false表示不是
 */
bool isPalindrome(int x)
{
	if( x < 0 )
	{
		return false;
	}
            
    long res = 0;
    int temp = x;
    while( x/10 != 0)
    {
        res = res*10 + x%10;
        x = x/10;
    }
    res = res *10 + x;
        
   	if(res > INT_MAX)
        return false;
    
    if(res == temp)
        return true;
    else
        return false;
}