/**
 * 	LEETCODE844. Backspace String Compare
 */

/**
 * Given two strings S and T, return if they are equal when both are typed into empty text editors. 
 * # means a backspace character.
 * 
 * Example 1:
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * Example 2:
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * Example 3:
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * Example 4:
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * Note:
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * Follow up:
 * Can you solve it in O(N) time and O(1) space?
 */

bool backspaceCompare(char* S, char* T) {
    
    size_t sback, tback, slen, tlen;

	sback = tback = 0;
	for (slen = strlen(S), tlen = strlen(T);; --slen, --tlen) {
		for (; slen != 0; --slen)
			if (S[slen - 1] == '#')
				++sback;
			else if (sback != 0)
				--sback;
			else
				break;
        
		for (; tlen != 0; --tlen)
			if (T[tlen - 1] == '#')
				++tback;
			else if (tback != 0)
				--tback;
			else
				break;
        
		if (slen == 0 || tlen == 0 || S[slen - 1] != T[tlen - 1])
			break;
	}

	return slen == 0 && tlen == 0;
    
    
}