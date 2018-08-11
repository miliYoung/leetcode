/**
 * LEETCODE 3. Longest Substring Without Repeating Characters
 */

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

bool contain(char* s, char target)
{
	if(NULL == s)
	{
		return false;
	}
	
	int i = 0;
	for(i = 0; i < strlen(s); i++)
	{
		if(s[i] == target)
		{
			return true;
		}
	}
	
	return false;
}

/*s中肯定含有target，故不做判断*/
void remove_target(char* s, char target)
{
	if(NULL == s)
	{
		return ;
	}
	
	int i = 0;
	for(i = 0; i < strlen(s) - 1; i++)
	{
		if(s[i] == target)
		{
			break;
		}
	}
	
	while( i < strlen(s) - 1)
	{
		s[i] = s[i+1];
		i++;
	}
	
	s[strlen(s) - 1] = 0;
}

int lengthOfLongestSubstring(char* s) {
    if(NULL == s || 0 == strlen(s))
	{
		return 0;
	}
	
	int max = 0;
	int left = 0;
	int right = 0;
	int length = strlen(s);
	char* res = malloc(length + 1);
	if(res != NULL)
	{
		memset(res, 0 ,length + 1);
	}
	
	while(left < length && right < length)
	{
		if(contain(res, s[right]))
		{
			//删除对应的
			remove_target(res, s[left]);
			left++;
		}
		else
		{
			res[strlen(res)] = s[right];
			right++;
			max = max > (right- left)? max : right - left;
		}
	}
	
	free(res);
	
	return max;
}
