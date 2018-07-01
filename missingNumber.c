/**
 * LEETCODE 268. Missing Number
 */

/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * 
 * Example 1:
 * Input: [3,0,1]
 * Output: 2
 * 
 * Example 2:
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */


int missingNumber(int* nums, int numsSize) {
    
    if(NULL == nums || 0 == numsSize)
    {
        return 0;
    }
    
    long sum = (numsSize + 1) * numsSize/2;
    long array_sum = 0;
    int i = 0;
    for(i = 0; i < numsSize; ++i)
    {
        array_sum += nums[i]; 
    }
    
    return (int)(sum - array_sum);
    
    
}