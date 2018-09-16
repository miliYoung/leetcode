/**
 * LEETCODE 55. Jump Game
 */

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Example 2:
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 *            jump length is 0, which makes it impossible to reach the last index.
 */

/**
*   经典的染色问题：枚举每一位时都在判断是否被染色过（从而决定是否能够到达该点且能否继续往前走），假设在某一瞬间，
*   index=m 的位置已经被染色了，那么 * *index=n (n<=m) 的位置肯定已经被染色过了，我们维护一个最右边被染色的点，
*   如果当前枚举点在该点的左侧，那么当前点已经被染色，否则即可停止遍历（因为右边的点再* 也不可能被染色到了）。
**/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t len = nums.size();
        int right = 1;
        int i = 0;
        for( i = 0; i < len; i++)
        {
            if(right < i + 1)
            {
                break;
            }
            
            right = right > (i+1+nums[i]) ? right : (i+1+nums[i]);
        }
        
        return right >= len;
    }
};