/**
 *       LEETCODE 125. Valid Palindrome
 */

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 * 
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * Example 2:
 * Input: "race a car"
 * Output: false
 */

/**
 * [isPalindrome description] 判断一个字符串是否是回文数
 * @param  s [description] 待判断的字符串
 * @return   [description] true表示是，false表示不是
 * @Note 1.注意排除数字 2.注意全部都是符号的特殊情况 3.减少运行时间，在内部循环中做大小的转换（注意数字‘0’和‘P’）
 */
bool isPalindrome(char* s)
{
	if( NULL == s)
	{
		return false;
	}

	if(strlen(s) == 1) return true;

	int i = 0, j = strlen(s)-1;

	while(j > i)
	{
		while( (s[i] < 'a'|| s[i] > 'z') && (s[i] < 'A'|| s[i] > 'Z' ) && ( s[i] <'0' || s[i] > '9'))
		{
            if(i < j)
            {
                i++;
            }
            else
            {
                return true;
            }
		}

		while((s[j] < 'a'|| s[j] > 'z') && (s[j] < 'A'|| s[j] > 'Z' ) && ( s[j] <'0' || s[j] > '9'))
		{
			if(j > i)
            {
                j--;
            }
            else
            {
                return true;
            }
		}
        
        if (s[i]>='a' && s[i]<='z')
        {
        	s[i] = s[i] - 'a' + 'A';
        }    
        if (s[j]>='a' && s[i]<='z')
        {
            s[j] = s[j] - 'a' + 'A';
        }
        
		if (s[i] == s[j])
		{
            i++;
            j--;
        }
        else
        {
            return false;
        }	
	}

	return true;
}