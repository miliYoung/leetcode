/**
 * LEETCODE 283. Move Zeroes
 */


/**
 * Given an array nums, write a function to move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */


void moveZeroes(int* nums, int numsSize) 
{
    if( NULL == nums || 0 == numsSize)
    {
    	return ;
    }

    int i = 0;
    int j = 0;
    for( i = 0; i < numsSize;)
    {
    	if( 0 == nums[i])
    	{
    		for(j = i; j < numsSize-1; ++j)
    		{
    			nums[j] = nums[j+1];
    		}
    		nums[j] = 0;
    		numsSize = numsSize - 1;
    	}
        else
        {
            i++;
        }
        
    }

    return ;
}