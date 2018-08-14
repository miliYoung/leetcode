/**
 * LEETCODE 479. Largest Palindrome Product
 */

/**
 * Find the largest palindrome made from the product of two n-digit numbers.
 * Since the result could be very large, you should return the largest palindrome mod 1337.
 * 
 * Example:
 * Input: 2
 * Output: 987
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 * Note:
 * The range of n is [1,8].
 */

long reverse(long num)
{
    long rev = 0;
    while(num)
    {
        rev = rev*10 + num%10;
        num/=10;
    }
    return rev;
}

int largestPalindrome(int n) {
    if(n == 1) return 9; 
    
    long left = pow(10, n) - 2;
    long i = 0;
    while(left > 2)
    {
        long t = left * pow(10,n);
        long temp = t + reverse(left); /*构造回文数*/
        
        for(i = pow(10,n) - 1; i*i > temp; i--)
        {
            if(temp % i == 0 && (temp/i) < pow(10,n) - 1)
            {
                return temp%1337;
            }
        }  
        left--;
    }
    
    return 0;
}