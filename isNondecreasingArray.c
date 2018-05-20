/**
 *       LEETCODE 665 Non-decreasing Array
 */

/**
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 * 
 * Example 1:
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
 * 
 * Example 2:
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one element.
 * Note: The n belongs to [1, 10,000].
 */

/**
 * [checkPossibility description]  检查一个数列是否可以通过替换一个元素实现省数列
 * @param  nums     [description]  待检查的数列
 * @param  numsSize [description]  数列的长度
 * @return          [description]  true 表示可以，false表示不可以
 */
bool checkPossibility(int* nums, int numsSize)
{
    if(NULL == nums || 0 == numsSize)
    {
    	return false;
    }

    int i = 0;
    int count = 0;
    for(i = 1; i < numsSize ; ++i)
    {
    	if(nums[i] < nums[i-1])
    	{
    		if( i == 1 || i = numsSize - 1)	//可以通过修改nums[0]和nums[numsSize - 1]实现
    		{
    			count++;
    		}
    		else if(nums[i+1] > nums[i-1] || nums[i] > nums[i - 2]) //可以替换三个数中间的那个数实现
    		{
    			count++;
    		}
    		else
    		{
    			return false;
    		}
    	}

    	if(count >= 2)
    	{
    		return false;
    	}
    }

    return true;
}