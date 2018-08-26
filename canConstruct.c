/**
 * LEETCODE 383. Ransom Note
 */

/**
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 * Each letter in the magazine string can only be used once in your ransom note.
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 */

bool canConstruct(char* ransomNote, char* magazine) {
    int lenA = strlen(ransomNote);
    int lenB = strlen(magazine);
    int tbl[26] = {0};
    
    int i = 0;
    for(i = 0; i < lenB; ++i)
    {
        tbl[magazine[i] - 'a']++;
    }
    
    for(i = 0; i < lenA; ++i)
    {
        tbl[ransomNote[i] - 'a']--;
    }
    
    for(i = 0; i < 26; ++i)
    {
        if(tbl[i] < 0)
        {
            return false;
        }
    }
    
    return true;
}