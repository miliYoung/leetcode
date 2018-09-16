/**
 * LEETCODE 611. Valid Triangle Number
 */

/**
 * Given an array consists of non-negative integers, 
 * your task is to count the number of triplets chosen from the array that can make triangles 
 * if we take them as side lengths of a triangle.
 * 
 * Example 1:
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * Note:
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        size_t len = nums.size();
        if(len < 3) return 0;
        
        /*先进行排序*/
        sort(nums.begin(), nums.end());
        
        int res=0;
        for(int i=0;i<len-2;i++)
        {
        	for(int j=i+1,k=i+2;k<len;k++)
            {
        		while(k>j && nums[i]+nums[j]<=nums[k])
                {
                    j++;
                }
                
        		res+=k-j;
        	}
        }
        
        return res;
    }
};