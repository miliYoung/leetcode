/**
 * LEETCODE 349. Intersection of Two Arrays
 */

/**
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * Example 2:
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
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


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1 == NULL || nums1Size == 0) 
        return nums2;
    if(nums2 == NULL || nums2Size == 0) 
        return nums1;
    
    int i = 0;
    int j = 0;
	int temp = -1;    
    int len = nums1Size > nums2Size ? nums1Size : nums2Size;
    int* res = malloc(len * sizeof(int));
    if(NULL != res)
    {
        memset((char* )res, 0, sizeof(int) * len);
    }
    else
    {
        return NULL;
    }
    
	*returnSize = 0;
	
    //对数组nums1和nums2进行快速排序、
    quick_sort(nums1,0,nums1Size-1);
    quick_sort(nums2,0,nums2Size-1);
   
    for(; i < nums1Size && j < nums2Size;)
    {
        if(nums1[i] == nums2[j])
        {
            if(nums1[i] != temp || *returnSize == 0)
            {
                res[*returnSize] = nums1[i];
                temp = nums1[i];
                (*returnSize)++;
            }
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j])
        {    
            i++;
        }
        else
        {
            j++;
        }
    }
    
    return res;
}


