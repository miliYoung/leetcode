/**
 * LEETCODE 415. Add Strings
 */

/**
 * 
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 * Note:
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

char* addStrings(char* num1, char* num2) {
    if(NULL == num1) return num2;
    if(NULL == num2) return num1;
    
    size_t lenA = strlen(num1);
    size_t lenB = strlen(num2);
    size_t len = 0;
    int i = 0;
    int j = 0;
    int c = 0;
    int k = 0;
    char* res = NULL;
    
    if(lenA > lenB){
        len = lenA;  
    } 
    else{
        len = lenB;
    }
    
    len = len+1;
    res = malloc(len+1);
    if(res != NULL)
    {
        memset(res, 0 ,len+1);
    }
    else
    {
        return res;
    }
    
    i = lenA - 1;
    j = lenB - 1;
    k = len - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? num1[i--] - '0': 0;
        c += j >= 0 ? num2[j--] - '0': 0;
        res[k] = c%10 + '0';
        c = c/10;
        k--;
    }

    
    return res+k+1;
}