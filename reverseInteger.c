/**
 *        LEETCODE 7  Reverse Integer
 */

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 * Example 1:
 * Input: 123
 * Output: 321
 * 
 * Example 2:
 * Input: -123
 * Output: -321
 *
 * Example 3:
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
 * [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

/**
 * [reverse description] 反转数字
 * @param  x [description] 待转换的数字
 * @return   [description] 转换结果
 * @note  注意在使用乘法的时候应该避免越界问题
 */
int reverse(int x) {

	int temp = x;
    long res = 0;

    if(x < 0) temp = -x;
        
    while(temp > 0)
    {
        res = res*10 + temp%10;
        temp = temp/10;
    }

    if(res > INT_MAX)
    {
        return 0;
    }

    if( x < 0 )
    {
        res = -res;
    } 
    
    return (int)res;
}