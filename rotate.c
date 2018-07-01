/**
 * 	LEETCODE 189. Rotate Array
 */

/**
 * Example 1:
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * Example 2:
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 */


void rotate(int* nums, int numsSize, int k) {
    
    if(NULL == nums || 0 == numsSize || 0 == k)
    {
    	return ;
    }

    int i = 0, j = 0;
    int temp = 0;
    for( i = 0; i < k ; i++ )
    {
    	temp = nums[numsSize-1];
    	for(j = numsSize-1; j > 0; j--)
    	{
    		nums[j] = nums[j - 1];
    	}
    	nums[0] = temp;
    }

    return ;
}