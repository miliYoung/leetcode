/**
 * LEETCODE 344. Reverse String
 */


/**
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */


char* reverseString(char* s)
{
	int length=strlen(s);
    
    char* reverse=NULL;
    reverse = (char*)calloc(length + 1, sizeof(char));
    
    int j=length-1;
    for(int i=0; i< length; i++)
    {
        reverse[i]=s[j];
        j--;
    }
    return reverse;
}