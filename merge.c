/**
 * 
 */

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * 
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 * 
 * Example:
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 */

void merge(int* nums1, int m, int* nums2, int n) {
    
    int i = 0;
    int length = m;
    int j = 0;
    for( i = 0; i < length && j < n; i++)
    {
        if(nums1[i] < nums2[j])
        {
            continue;
        }
        else
        {
            int k = length;
            while(k > i)
            {
                nums1[k] = nums1[k-1];
                k--;
            }
            nums1[k] = nums2[j];
            length = length + 1;
        }
        j++; 
    }
    
    for(; j < n; j++)
    {
        nums1[i] = nums2[j];
        i++;
    }
}