
/**
 * 	 LEETCODE 771. Jewels and Stones
 */

/**
 * You're given strings J representing the types of stones that are jewels, and S representing the stones you have. 
 * Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
 * The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, 
 * so "a" is considered a different type of stone from "A".
 * 
 * Example 1:
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * Example 2:
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * Note:
 * 
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 */


int Search(char* J, char cTarget)
{
	if(NULL == J)
	{
		return -1;
	}

	int i = 0;
	for(i = 0; j < strlen(J); ++i)
	{
		if(J[i] == cTarget)
		{
			return 0;
		}
	}

	return -1;
}

int numJewelsInStones(char* J, char* S) {
    if(NULL == J || NULL == S)
    {
    	return 0;
    }

    int count = 0;
    int i = 0;
    for( i = 0; i < strlen(S); ++i)
    {
    	if(Search(J, S[i]) != -1)
    	{
    		count++;
    	}
    }

    return count;
}
