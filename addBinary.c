/**
 * LEETCODE 67. Add Binary
 */

/**
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */

char* addBinary(char* a, char* b) {
    if(NULL == a) return b;
    if(NULL == b) return a;
    
    size_t lenA = strlen(a);
    size_t lenB = strlen(b);
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
        c += i >= 0 ? a[i--] - '0': 0;
        c += j >= 0 ? b[j--] - '0': 0;
        res[k] = c%2 + '0';
        c = c/2;
        k--;
    }
    
    return res+k+1;
}