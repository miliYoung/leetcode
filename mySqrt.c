/**
 * 	LEETCODE 69. Sqrt(x)
 */

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * 
 * Example 1:
 * Input: 4
 * Output: 2
 * 
 * Example 2:
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 */

/**
 * [mySqrt description]    计算一个数的开平方
 * @param  x [description] 待计算的数
 * @return   [description] 返回数的开平方
 * @note  注意基础的数学公式还是不能忘记的
 */
int mySqrt(int x) 
{
	double ans    = x;
    double delta  = 0.0001;
    while (fabs(pow(ans, 2) - x) > delta) 
    {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}