/**
 * 	LEETCODE 697. Degree of an Array
 */

/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 * 
 * Example 1:
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * Example 2:
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 */

int findShortestSubArray(int* nums, int numsSize) {
    if( NULL == nums || 0 == numsSize )
    {
        return 0;
    }
    
    int minLen = 50000;
    int currLen = 0;
    int maxfre = 0;
    int fre[50001] = {0};
    int pos[50001] = {0};
    
    if(numsSize == 1)
    {
        return 1;
    }
    
    int i = 1;
    for(i = 1; i <= numsSize; i++)
    {
        if(pos[nums[i-1]] != 0)
        {
            fre[nums[i-1]]++;
            currLen = i - pos[nums[i-1]]+1;
            if(maxfre < fre[nums[i-1]])
            {
                maxfre = fre[nums[i-1]];
                minLen = currLen;
            }
            else if(maxfre == fre[nums[i-1]])
            {
                minLen = currLen < minLen ? currLen:minLen;
            }
        }
        else
        {
            pos[nums[i-1]] = i;
        }
    }
    
    if(maxfre == 0)
    {
        return 1;
    }
    
    return minLen;
    
}