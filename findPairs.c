/**
 * 	LEETCODE 532. K-diff Pairs in an Array
 */

/**
 * Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
 * Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array 
 * and their absolute difference is k.
 * 
 * Example 1:
 * Input: [3, 1, 4, 1, 5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 * Although we have two 1s in the input, we should only return the number of unique pairs.
 * 
 * Example 2:
 * Input:[1, 2, 3, 4, 5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
 * 
 * Example 3:
 * Input: [1, 3, 1, 5, 4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 * Note:
 * The pairs (i, j) and (j, i) count as the same pair.
 * The length of the array won't exceed 10,000.
 * All the integers in the given input belong to the range: [-1e7, 1e7].
 */

/**
 * [findPairs description]
 * @param  nums     [description]
 * @param  numsSize [description]
 * @param  k        [description]
 * @return          [description] not deal
 */
int quick_sort(int* num, int begin, int end)
{
    if(begin < 0 || begin > end || NULL == num )
    {
        return -1;
    }
    if (begin < end)
    {
        int i = begin, j = end, x = num[begin];
        while (i < j)
        {
            while(i < j && num[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                num[i++] = num[j];
 
            while(i < j && num[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                num[j--] = num[i];
        }
        num[i] = x;
        
        quick_sort(num, begin, i - 1); // 递归调用
        
        quick_sort(num, i + 1, end);
    }
    
    return 0;
}


int findPairs(int* nums, int numsSize, int k) 
{
    if(NULL == nums || 0 == numsSize || k < 0)
    {
        return 0;
    }
    
    int res = 0;
    quick_sort(nums, 0, numsSize-1);
    int i= 0;
    int j = 0;
    for(int i=0; i < numsSize; i++)
    {
        for(int j=i+1; j < numsSize; j++)
        {
            if(nums[j] - nums[i] == k)
            {
                    res++;
                    break;
            }
        }
        
        while(i<numsSize-1 && nums[i] == nums[i+1])
        {
            i++;
        }    
    }
        
    return res;
}
