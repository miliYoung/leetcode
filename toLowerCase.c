/**
 * 	LEETCODE 709. To Lower Case
 */

/**
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 * 
 * Example 1:
 * Input: "Hello"
 * Output: "hello"
 * 
 * Example 2:
 * Input: "here"
 * Output: "here"
 * 
 * Example 3:
 * Input: "LOVELY"
 * Output: "lovely"
 */

char* toLowerCase(char* str) {
    
    if(NULL ==  str || 0 == strlen(str))
    {
        return NULL;
    }
    
    int i = 0;
    for(i = 0; i < strlen(str); i++)
    {
       if( str[i]  >= 'A' &&  str[i] <= 'Z')
       {
            str[i] = str[i] + 0x20;
       }
    
    }
    
    return str;
}