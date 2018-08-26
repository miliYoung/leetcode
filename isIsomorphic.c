/**
 * LEETCODE 205. Isomorphic Strings
 */

/**
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 * Note:
 * You may assume both s and t have the same length.
 */

bool isIsomorphic(char* s, char* t) {
    if(NULL == s || NULL ==  t)
    {
        return false;
    }
    
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if(len_s != len_t)
    {
        return false;
    }
    
    char tbl_s[256] = {0};
    char tbl_t[256] = {0};
    int i = 0;
    for( i = 0; i < len_s; i++)
    {
        if(tbl_s[s[i]] != tbl_t[t[i]])
        {
            return false;
        }
        tbl_s[s[i]] = i+1;
        tbl_t[t[i]] = i+1;
    }
    return true;
    
}