/**
 * 	LEETCODE 169. Majority Element
 */

/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Example 1:
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 */

int majorityElement(int* nums, int numsSize) {
	if(NULL == nums || 0 == numsSize)
	{
		return 0;
	}    

	int i = 0;
    int major = nums[0];
    int count = 1;
    for(i = 1; i < numsSize; ++i)
    {
        if(count == 0)
        {
            major = nums[i];
        }
            
        if(major == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }       
    }
        
    return major;
}