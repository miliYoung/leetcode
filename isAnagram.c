/**
 * LEETCODE 242. Valid Anagram
 */

/**
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */


bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    if(len_s != len_t)
    {
        return false;
    }
    
    int temp[26] = {0};
    int i = 0;
    for( i = 0; i < len_s; i++)
    {
        temp[s[i] - 'a']++;
        temp[t[i] - 'a']--;
    }
    
    for(i = 0; i < 26; i++)
    {
        if(temp[i] != 0)
        {
            return false;
        }
    }
    
    return true;
}