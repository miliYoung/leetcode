/**
 * LEETCODE 448. Find All Numbers Disappeared in an Array
 */

/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * 
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 */


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    if(NULL == nums || 0 == numsSize)
    {
        return NULL;
    }
    
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int i = 0;
    int index = 0;
    int j = 0;
    for(i = 0; i< numsSize; ++i)
    {
        index = abs(nums[i]) - 1;
        if(nums[index] > 0)
        {
            nums[index] = -nums[index];
        }
        else
        {
            (*returnSize)++;
        }
    }
    
	for(i = 0; i< numsSize; ++i)
	{
		if(nums[i] > 0)
		{
			*(res + j) =  i+1;
			j++;
		}
	}
    
    return res;
    
}