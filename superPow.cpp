/**
 * LEETCODE 372. Super Pow
 */

/**
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
 * Example 1:
 * Input: a = 2, b = [3]
 * Output: 8
 * 
 * Example 2:
 * Input: a = 2, b = [1,0]
 * Output: 1024
 */

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        
        /* 运用了公式(a*b)%c = (a%c)*(b%c)%c*/
        int res = 1;
        int i = 0;
        size_t size = b.size();
        
        for(i = 0; i < size; i++)
        {
            res = pow_ex(res,10) * pow_ex(a,b[i])%1337;   
        }
        
        return res;
    };
    
    int pow_ex(int a, int b)
    {
        if(0 == b) return 1;
        if(1 == b) return a%1337;
        
        return pow_ex(a % 1337, b/2) * pow_ex(a % 1337, b - b/2) % 1337;
    }
};