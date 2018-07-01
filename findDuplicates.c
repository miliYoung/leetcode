/**
 * 	LEETCODE 442. Find All Duplicates in an Array
 */

/**
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    
    if(NULL == nums || numsSize == 0 )
    {
        return NULL;
    }
    
    int* res = (int*)malloc(sizeof(int) * numsSize);
    if(NULL == res)
    {
        return NULL;
    }
    
    int i = 0;
    int index = 0;
    *returnSize = 0;
    for(i = 0; i <numsSize; ++i)
    {
        index = abs(nums[i]) - 1;
        if(nums[index] > 0 )
        {
            nums[index] = -nums[index];
        }
        else
        {
            *(res + (*returnSize)) = abs(nums[i]);
            *returnSize += 1;
        }
    }
    
    return res;
}