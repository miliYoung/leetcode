/**
 * LEETCODE 371. Sum of Two Integers
 */


/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 * Example:
 * Given a = 1 and b = 2, return 3.
 * Credits:
 * Special thanks to @fujiaozhu for adding this problem and creating all test cases.
 */

int getSum(int a, int b) 
{
	if(a == 0) return b;

    int x = a ^ b;
    int c = (a & b) << 1;
        
    return getSum(c, x);
}