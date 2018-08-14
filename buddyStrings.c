/**
 * LEETCODE 859. Buddy Strings
 */

/**
 * Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
 * 
 * Example 1:
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * Example 2:
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * Example 3:
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * Example 4:
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * Example 5:
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * Note:
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 */

bool buddyStrings(char* A, char* B) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int tmp = 0;
    char sztmp[26] = {0};
    
    if(lenA != lenB) return false; 
    if(lenA == 0) return false;
    
    int i = 0;
    int* res = malloc(sizeof(int) * lenA);
    if(NULL != res)
    {
        memset(res, 0 ,sizeof(int) * lenA);
    }
    else
    {
        return false;
    }
    
    int j = 0;
    for(i = 0; i < lenA; i++)
    {
        if(A[i] != B[i])
        {
            res[j] = i;
            j++;
        }
    }
    
    if(j == 0)
    {
       for(i = 0; i < lenA; i++)
       {
           if(sztmp[A[i] - 'a'])
           {
               free(res);
               return true;
           }
           else
           {
               sztmp[A[i] - 'a'] = true;
           }
       }
        
        free(res);
        return false;
    }
    
    if(j != 2)
    {
        free(res);
        return false;
    }
    
    if(A[res[0]] == B[res[1]] && A[res[1]] == B[res[0]])
    {
        free(res);
        return true;
    }
    
    free(res);
    return false;
}