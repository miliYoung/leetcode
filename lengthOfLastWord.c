/**
 * LEETCODE 58. Length of Last Word
 */

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * Example:
 * Input: "Hello World"
 * Output: 5
 */

int lengthOfLastWord(char* s) {
    
    if(s == NULL)
    {
        return 0;
    }
    
    int i = strlen(s) - 1;
    int count = 0;
    
    while(*(s+i) == ' ')
    {
        i--;
    }
    
    for( ; i >=0; i--)
    {
        if(*(s+i) != ' ')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    
    return count;
}