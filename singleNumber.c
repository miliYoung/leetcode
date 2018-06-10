/**
 * 	LEETCODE 136. Single Number
 */

/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * 
 * Example 1:
 * Input: [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * Input: [4,1,2,1,2]
 * Output: 4
 */


int singleNumber(int* nums, int numsSize) 
{
	if( NULL == nums || numsSize == 0)
	{
		return 0;
	} 

	int res = 0;
	int i = 0;
	for( i = 0; i < numsSize; ++i)
	{
		res = res ^ nums[i];
	}   

	return res;
}