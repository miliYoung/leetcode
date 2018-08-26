/**
 * LEETCODE 680. Valid Palindrome II
 */

/**
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 * 
 * Example 1:
 * Input: "aba"
 * Output: True
 * 
 * Example 2:
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * Note:
 * The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */

bool isPalindrome(char* s, int start, int end)
{
    if(NULL == s)
    {
        return false;
    }

    while(start < end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}


bool validPalindrome(char* s) {
    if(NULL == s)
    {
        return false;
    }
    
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
        i++; 
        j--;
    }
    
    return true;
}