/**
 * LEETCODE 434. Number of Segments in a String
 */

/**
 * Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * Input: "Hello, my name is John"
 * Output: 5
 */

int countSegments(char* s) {
    
    int count = 0, i, str_len;
    char c = ' ';
    str_len =strlen(s);
    i = 0;
    while (i < str_len) {
        while (i < str_len && s[i] == c) 
            i++;
        if (i == str_len) break;
        i++;
        while (i < str_len && s[i] != c)
            i++;
        count++;
    }
    
    return count;
}