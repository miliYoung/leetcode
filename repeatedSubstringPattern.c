/**
 * 	LEETCODE 459. Repeated Substring Pattern
 */

/**
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 * 
 * Example 1:
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * Example 2:
 * Input: "aba"
 * Output: False
 * 
 * Example 3:
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */

bool repeatedSubstringPattern(char* s) {
    
    int len = strlen(s);
    if( 0  == len )
    {
        return false;
    }
    
    char* tmp = malloc(len+1);
    int i = 0;
    int j = 0;
    
    for (i = len/2; i >= 1; --i) 
    {
       if (len % i == 0)
       {
           int c = len / i;
           memset(tmp, 0, len+1);
           for (j = 0; j < c; ++j)
           {
               memcpy(tmp + j*i, s, i);
           }
           
           if (strcmp(s,tmp) == 0)
           {
              free(tmp);
              return true;  
           } 
        }
    }
    
    free(tmp);
    return false;
}