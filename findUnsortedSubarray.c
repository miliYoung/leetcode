/**
 *     LEETCODE 581. Shortest Unsorted Continuous Subarray
 */


/**
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
 * then the whole array will be sorted in ascending order, too.
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 * 
 * Note:
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means <=.
 */

int findUnsortedSubarray(int* nums, int numsSize) 
{
    if(NULL == nums || numsSize == 0)
    {
        return 0;
    }
    
    int beg = -1;
    int end = -2;
    int min = *(nums + numsSize - 1);
    int max = *(nums);
    int i = 0;
    for(i = 1; i < numsSize; i++)
    {
        if(max < (*(nums+i)))
        {
            max = *(nums+i);
        }
        
        if(*(nums + numsSize - 1 -i) < min)
        {
            min = *(nums + numsSize - 1 -i);
        }
        
        if(*(nums + i) < max) end = i;
        
        if(*(nums + numsSize - 1 -i) > min) beg = numsSize - 1 - i; 
        
    }

    return end - beg + 1;
}