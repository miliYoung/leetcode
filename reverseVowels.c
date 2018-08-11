/**
 * LEETCODE 345. Reverse Vowels of a String
 */

/**
 * Write a function that takes a string as input and reverse only the vowels of a string.
 * 
 * Example 1:
 * Input: "hello"
 * Output: "holle"
 * 
 * Example 2:
 * Input: "leetcode"
 * Output: "leotcede"
 * Note:
 * The vowels does not include the letter "y".
 */

bool isVowel(char letter)
{
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
    {
        return true;
    }
    
    if(letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
    {
        return true;
    }
    
    return false;
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    if( 0 == len)
    {
        return s;
    }
    
    char* res = malloc(len+1);
    if(NULL == res)
    {
        return NULL;
    }
    else
    {
        memset(res, 0, len+1);
    }
    
    int i = 0;
    int j = 0;
    memcpy(res, s, len);
    for(i = 0,j = len - 1; i <= j;)
    {
        if(isVowel(res[i]) && isVowel(res[j]))
        {
            char temp;
            temp = res[i];
            res[i] = res[j];
            res[j] = temp; 
            i++;
            j--;
        }
        
        if(!isVowel(res[i]))
        {
            i++;
        }
        
        if(!isVowel(res[j]))
        {
            j--;
        }
    }
    
    return res;
    
}