/**
 * 	LEETCODE 830. Positions of Large Groups
 */

/**
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
 * Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
 * The final answer should be in lexicographic order.
 * 
 * Example 1:
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
 * 
 * Example 2:
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 * 
 * Example 3:
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 * Note:  1 <= S.length <= 1000
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    int len = strlen(S);
    int i = 0;
    int count = 0;
    int j = 0;
    int index = -1;
    
    for(i = 0; i < len - 1; i++)
    {
        if(S[i] == S[i+1])
        {
            count++;
        }
        
        if(S[i] != S[i+1] || i == len - 2)
        {
            if(count >= 2)
            {
                (*returnSize)++;
            }
            count = 0;
        }
    }

    
    *columnSizes = (int *)malloc(sizeof(int)*(*returnSize));
    int** res = (int**)malloc((*returnSize)*sizeof(int*));
    for(i = 0; i < (*returnSize); i++)
    {
        *(res+i) = (int*)malloc(2 * sizeof(int));
         *(*columnSizes + i) = 2;
    }
    
    
    for(i = 0; i < len - 1; i++)
    {
        if(S[i] == S[i+1])
        {
            if(count == 0)
            {
                index = i;
            }
            count++;
        }
        
        if( S[i] != S[i+1] || i == len - 2)
        {
            if(count >= 2)
            {
                 *(*(res+j)) = index;
                 if(i == len - 2 && S[i] == S[i+1])
                 {
                     *(*(res+j)+1) = i+1;
                 }
                 else
                 {
                     *(*(res+j)+1) = i;
                 }
                 j++;
            }
            count = 0;
            index = -1;
        }
    }
    
    return res; 
}