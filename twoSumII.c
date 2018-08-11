/**
 * LEETCODE 167. Two Sum II - Input array is sorted
 */

/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * 
 * Example:
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    if( NULL == numbers || 0 == numbersSize )
    {
        return NULL;
    }
    
    int* res = malloc(2 * sizeof(int));
    if(res != NULL)
    {
        memset((char*)res, 0 , 2 * sizeof(int));
    }
    else
    {
        return NULL;
    }
    
    int i = 0;
    int j = numbersSize - 1;
    while(i < j)
    {
        if(numbers[i] + numbers[j] > target)
        {
            j = j - 1;
        }
        else if(numbers[i] + numbers[j] < target)
        {
            i = i + 1;
        }
        else
        {
            res[0] = i+1;
            res[1] = j+1;
            *returnSize = 2;
            return res;
        }
    }
    
    return res;
    
}