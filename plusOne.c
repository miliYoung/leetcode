/**
 *        LEETCODE 66  Plus One
 */

/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, 
 * and each element in the array contain a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * Example 2:
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 */

/**
 * @param	int *digits 	待计算的数组 
 * @param	int digitsSize	数组长度
 * @param	returnSize		返回数组的长度	
 * @return  结果数组
 * @note 	在分配内存的时候注意乘以sizeof(int)
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int* res = NULL;
    int  i = digitsSize -1;
    int extra = 0; //表示在+1的过程中存在进位现象

    if(NULL == digits || 0 == digitsSize || NULL == returnSize)
    {
    	return NULL;
    }

    digits[digitsSize - 1] += 1; 
    while( i >= 0)
    {
    	if(digits[i] + extra >= 10 )
    	{
    		digits[i] = (digits[i] + extra)%10;
    		extra = 1;
    	}
    	else
    	{
            digits[i] += extra;
    		extra = 0;
    		break;
    	} 
        i--;
   	}

   	res = malloc((extra + digitsSize) * sizeof(int));
   	if(NULL == res)
   	{
   		return NULL;
   	}
   	else
   	{
   		memset(res, 0 , (extra + digitsSize) * sizeof(int));
   	}
    
    if(extra != 0)
    {
        res[0] = extra;
    }
   
   	for( i = extra; i < digitsSize + extra; ++i)
   	{
   		res[i] = digits[i - extra];
   	}

   	(*returnSize) = digitsSize + extra;

    return res;
}
