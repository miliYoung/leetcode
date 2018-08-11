/**
 * LEETCODE 704. Binary Search
 */

/**
 * Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
 * 
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * 
 * Example 2:
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 */

int search(int* nums, int numsSize, int target) {
    if(NULL == nums || 0 == numsSize)
    {
        return 0;
    }
    
    int high = numsSize-1;
    int low = 0;
    int middle = (high + low)/2;
    
    while(high >= low)
    {
        if(nums[middle] > target )
        {
            high = middle - 1;
        }
        else if(nums[middle] < target)
        {
            low = middle + 1;
        }
        else
        {
            return middle;
        }
        middle = (high + low)/2;
    }
    
    return -1;
    
}