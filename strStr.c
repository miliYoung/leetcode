/**
 * 	LEETCODE 28. Implement strStr()
 */

/**
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great question to ask during an interview.
 * For the purpose of this problem, we will return 0 when needle is an empty string. 
 * This is consistent to C's strstr() and Java's indexOf().
 */

/**
 * [strStr description]
 * @param  haystack [description]
 * @param  needle   [description]
 * @return          [description] 
 * @note 这不是一个好的解法，时间复杂度为O(n^2)
 */

int strStr(char* haystack, char* needle) {
    
    int pos = -1;
    int i = 0;
    int j = 0;
    int lena = strlen(haystack);
    int lenb = strlen(needle);
    
    if(lena < lenb)
    {
        return -1; 
    }
    
    if(lenb == 0)
    {
        return 0;
    }
    
    for(i = 0; i < lena - lenb + 1; )
    {
        j = 0;
        if(haystack[i] == needle[j])
        {
           pos = i; 
           while(j < lenb)
           {
               if(haystack[++i] != needle[++j])
               {
                   break;
               }             
           }
            
           if(j == lenb)
           {
               return pos;
           }         
        }
        i = i-j+1;
    }
    
    return -1;
    
}