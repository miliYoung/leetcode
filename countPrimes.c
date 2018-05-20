/**
 *       LEETCODE 204. Count Primes
 */

/**
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */

/**
 * [countPrimes description] 计算0到n中间素数的个数
 * @param  n [description]   区间n
 * @return   [description]   素数的个数
 * @note  本例中采用了排除法，利用空间换取了时间的效率
 */
int countPrimes(int n) 
{
    int i = 0, j = 0;
    int count = 0;
    bool* flag = NULL;
    if(n <= 1) return 0;
    
    flag = malloc(n*sizeof(bool));
    if(NULL == flag)
    {
        return 0;
    }
    else
    {
        memset(flag, true, n*sizeof(bool));
    }
    
    for(i = 2; i <= n; ++i)
    {
        if(flag[i])
        {
            count++;
            for(j = 2*i; j <=n; j = j+i)
            {
                flag[j] = false;
            }
        }
    }
    
    free(flag);
    
    return count;
}