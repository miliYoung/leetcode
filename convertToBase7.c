/**
 * 	LEETCODE 504. Base 7
 */

/**
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * Input: 100
 * Output: "202"
 * Example 2:
 * Input: -7
 * Output: "-10"
 * Note: The input will be in range of [-1e7, 1e7].
 */

#define MAX_NUM 128

void reverse(char* res, int begin, int end)
{
    int i = 0;
    int j = 0;
    for(i = begin, j = end; i <= j; i++, j--)
    {
        int temp = 0;
        temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
}


char* convertToBase7(int num) {
    
    char* res = malloc(MAX_NUM);
    if(res == NULL)
    {
        return res;
    }
    else
    {
        memset(res,0, MAX_NUM);
    }
    
    int i = 0;
    if(num < 0)
    {
        *res = '-';  
        num = abs(num);
        i = 1;
    }
    else if(num == 0)
    {
        *res = '0';
    }
    
    while(num)
    {
        res[i++] = num % 7 + '0';
        num = num/7;
    }
    
    
    if( *res == '-')
    {
        reverse(res,1,strlen(res)-1);
    }
    else
    {
        reverse(res, 0, strlen(res)-1);
    }
    
    return res;
}