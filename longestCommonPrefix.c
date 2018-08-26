/**
 * LEETCODE  14. Longest Common Prefix
 */

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: ["dog","racecar","car"]
 * 
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * Note:
 * All given inputs are in lowercase letters a-z.
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    if( NULL == strs || strsSize == 0)
    {
        return "";
    }    
    
    if( 1 == strsSize )
    {
        return strs[0];
    }
    int i = 0;
    int minLen = strlen(strs[0]);
    for(i  = 0; i < strsSize; i++)
    {
        int len = strlen(strs[i]);
        if(len < minLen)
        {
            minLen = len;
        }
    }
    
    if(minLen == 0) return "";
    
    char* res = malloc(minLen);
    memset(res, 0 ,minLen);
    int j = 0;
    int returnLen = 0;
    for(j = 0; j < minLen; j++)
    {
        char tmp = strs[0][j];
        printf("%c ",tmp);
        for(i = 1; i < strsSize; ++i)
        {
            if(tmp != strs[i][j])
            {
                return res;
            }
        }
        res[j] = tmp; 
        
    }
    res[j] = 0;
    
    return res;
    
    
}
