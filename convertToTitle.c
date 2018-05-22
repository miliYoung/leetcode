/**
 * 	LEETCODE 168. Excel Sheet Column Title
 */

/**
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB 
 *  
 *  ...
 *  Example 1:
 *  Input: 1
 *  Output: "A"
 *  
 *  Example 2:
 *  Input: 28
 *  Output: "AB"
 *  Example 3:
 *  Input: 701
 *  Output: "ZY"
 */

/**
 * [convertToTitle description] 标题转换
 * @param  n [description]      待转换的数字
 * @return   [description]      转换后的标题
 * @note  1.注意使用常数和字符之间的差值 2.701 = 26*26 + 25 可考虑为逢25进1，但是‘A’对应数字0
 */
char* convertToTitle(int n) 
{
	int num = n;
    int count =0;
    int i = 0;
	
    while(n)
    {
       n = (n- 1)/26; //这里是需要注意的点
       count++; 
    }
	
    char* res = (char*)malloc(count * sizeof(char));
    if(NULL == res)
    {
        return NULL;            
    }
    else
    {
	memset( res, 0,sizeof(count * sizeof(char)));
    }		
    
    for(i = count -1; i >= 0 ; i--)
    {
        *(res+i) = 'A'+ (num - 1)%26;
        num = (num -1)/26;
		
    }
	
    return res;
}
