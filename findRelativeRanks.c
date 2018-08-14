/**
 * LEETCODE 506. Relative Ranks
 */

/**
 * Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: 
 * "Gold Medal", "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
 * For the left two athletes, you just need to output their relative ranks according to their scores.
 * Note:
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 */

void toString(int val, char* res)
{
	if(NULL == res)
	{
		return 0;
	}
	
	int n = 0;
	int i = 0;
	char temp = 0;
	while(val)
	{
		*(res+n) = val%10 + '0';
		val = val/10;
		n++;
	}
	
	for(i = 0; i < n/2; i++)
	{
		temp = res[i];
		res[i] = res[n-i-1];
		res[n-i-1] =temp;
	}

}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
    if( NULL == nums || numsSize == 0)
    {
        return NULL;
    }
    
    int i = 0;
    int j = 0;
    char** res = malloc(sizeof(char*) * numsSize);
    if(res != NULL)
    {
        for( i = 0; i < numsSize; i++)
        {
            *(res+i) = (char*)malloc(13);
            if(*(res+i) != NULL)
            {
                memset(*(res+i), 0 ,13);
            }
            else
            {
                int j= 0;
                for(j = i-1; j >=0; j--)
                {
                    free(*(res+j));
                }
                free(res);
                break;
            }
        }
    }
    else
    {
        return res;
    }
    
    for(i = 0; i < numsSize; ++i)
    {
        int count = 0;
        for(j = 0 ; j < numsSize; ++j)
        {
            if(nums[i] < nums[j])
            {
                count++;
            }
        }
        
        if(count == 0)
        {
            *(res+i) = "Gold Medal";
        }
        else if(count == 1)
        {
            *(res+i) = "Silver Medal";
        }
        else if(count == 2)
        {
            *(res+i) ="Bronze Medal";
        }
        else
        {
            toString(count+1,*(res+i));
        }
    }
    *returnSize = numsSize;
    
    return res;
    
}