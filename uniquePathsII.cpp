/**
 * LEETCODE 62. Unique Paths
 */

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * Example 2:
 * Input: m = 7, n = 3
 * Output: 28
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        //本题为动态规划问题
        //状态方程为f[i][j] = f[i-1][j] + f[i][j-1];
        //可以采用递归的思路进行解题
        
        int res = 0;
        int i = 0;
        int j = 0;
        int f[m][n] = {0};
        
        if(m == 0 || n == 0) return 1;
        
        for(j = 0; j < n; j++)
        {
            f[i][j] = 1;
        }
        
        j = 0;
        for(i = 0; i < m; i++)
        {
            f[i][j] = 1;
        }
        
        
        for(i = 1; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        
        return f[m-1][n-1];
    }
};