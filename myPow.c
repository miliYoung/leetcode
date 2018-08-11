/**
 * LEETCODE 50. Pow(x, n)
 */

/**
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * Example 2:
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * Example 3:
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * Note:
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */

double myPow(double x, int n) {
    double res = 1;
    long absn = 0;
    
    absn =  (n < 0) ? ((long)n *(-1)) : n;
    while (absn > 0) {
        if (absn & 1)
            res *= x;
        x *= x;
        absn >>= 1;
    }
    res = (n < 0) ? 1/res : res;
    return(res);  
}