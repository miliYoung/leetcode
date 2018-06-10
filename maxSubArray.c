/**
 *  LEETCODE 53. Maximum Subarray
 */

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

#define IN_MIN (~0>>1)

int maxSubArray(int* nums, int numsSize) {
    
    if(NULL == nums || numsSize == 0)
    {
        return 0;
    }
    
    int sum = 0;
    int max = INT_MIN;
    int i = 0; 
    for(i = 0; i < numsSize; i++)
    {
      if(nums[i] + sum >= 0) 
      {
          sum += nums[i];
          if(sum > max)
          {
              max=sum;
          }    
      }
      else{
          if(max<sum+nums[i])
          {
              max=nums[i];
          }
          sum = 0;
      }
   }
    
   return max; 
}