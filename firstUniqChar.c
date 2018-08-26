/**
 * LEETCODE 87. First Unique Character in a String
 */

/**
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 * Examples:
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * Note: You may assume the string contain only lowercase letters.
 */

int firstUniqChar(char* s) {
    int len = strlen(s);
    if( 0 == len )
    {
        return -1;
    }
    
    if( 1 == len)
    {
        return 0;
    }
    
    int temp[26] = { 0 };
    int bflag[26] = { 0 };
    int i = 0;
    int index = len+1;
    
    for( i = 0; i < len; ++i)
    {
        if(temp[s[i] - 'a'] == 0)
        {
            bflag[s[i] - 'a'] = i+1;
        }
        else
        {
            bflag[s[i] - 'a'] = 0;
        }
        
        temp[s[i] -'a']++;
    }
    
    for( i = 0; i < 26; i++ )
    {
        if(bflag[i] >= 1)
        {
            if(index > bflag[i] - 1)
            {
                index = bflag[i] - 1;
            }
        }
    }
    
    if(index == len+1)
    {
        return -1;
    }
    

    return index;
    
}