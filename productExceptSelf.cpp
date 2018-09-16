/**
 * LEETCODE 238. Product of Array Except Self
 */

/**
 * Given an array nums of n integers where n > 1,  
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Note: Please solve it without division and in O(n).
 * Follow up:
 * Could you solve it with constant space complexity? 
 * (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res_vec;
        size_t len = nums.size();
        
        if(len == 0) return res_vec;
        int res = 1;
        int count = 0;
        int tmp = 1;
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == 0)
            {
                count++;
                continue;
            }    
            res = res * nums[i];
        }
         
        for(int i = 0; i < len; i++)
        {
            if(0 == count)
            {
                int num = res / nums[i];
                res_vec.push_back(num);   
            }
            else
            {
                if(count >= 2)
                {
                    res_vec.push_back(0); 
                } 
                else
                {
                    if(nums[i] != 0)
                    {
                       res_vec.push_back(0);
                    }
                    else
                    {
                        res_vec.push_back(res);
                    }
                }
            }
        }
        
        return res_vec;
        
    }
};