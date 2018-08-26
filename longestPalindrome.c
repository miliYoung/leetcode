/**
 * LEETCODE 409. Longest Palindrome
 */

/**
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * Example:
 * Input:
 * "abccccdd"
 * Output:
 * 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

int longestPalindrome(char* s) {
    if(NULL == s)
    {
        return 0;
    }
    
    int i = 0; 
    int len = strlen(s);
    int Ss[26] = {0};
    int Bs[26] = {0};
    int sum = 0;
    int index = 0;
    
    for( i = 0; i < len; ++i)
    {
        if(s[i] <= 'z' && s[i] >= 'a')
        {
            Ss[s[i] - 'a']++;
        }
        else if(s[i] <= 'Z' && s[i] >= 'A')
        {
            Bs[s[i] - 'A']++;
        }
    }
    
   
    for(i = 0; i < 26; i++)
    {
        if(Ss[i]%2 == 1)
        {
            sum = sum + Ss[i] - 1;
            if(index == 0)
            {
                index = 1;
            }
        }
        else
        {
            sum = sum + Ss[i];
        }
    }
    
    for(i = 0; i < 26; i++)
    {
        if(Bs[i]%2 == 1)
        {
            sum = sum + Bs[i] - 1;
            if(index == 0)
            {
                index = 1;
            }
        }
        else
        {
            sum = sum + Bs[i];
        }
    }
    
    return sum + index;
}