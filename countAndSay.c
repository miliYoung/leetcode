/**
 * LEETCODE 38. Count and Say
 */

/**
 * he count-and-say sequence is the sequence of integers with the first five terms as following:
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string.
 * 
 * Example 1:
 * Input: 1
 * Output: "1"
 * 
 * Example 2:
 * Input: 4
 * Output: "1211"
 */

char* countAndSay(int n) {
    
    if(n == 1) return "1";

    char * cur = malloc(2);
    char * temp;
    cur[0] = '1';
    cur[1] = 0;

    int len, idx, j, count;
    for(int i = 2; i <= n; i++) {

        len = strlen(cur);
        temp = malloc(3 * len);
        memset(temp, 0, 3 * len);
        count = 1;
        for(idx = 1, j = 0; idx < len; idx++) {
            if(cur[idx] == cur[idx - 1]) count++;
            else {
                temp[j++] = '0' + count;
                temp[j++] = cur[idx - 1];
                count = 1;
            }
        }
        temp[j++] = '0' + count;
        temp[j] = cur[len - 1];
        free(cur);
        cur = temp;
    }
    return cur;
    
    
}