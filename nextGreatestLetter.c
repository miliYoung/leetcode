/**
 * LEETCODE 744. Find Smallest Letter Greater Than Target
 */

/**
 * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, 
 * find the smallest element in the list that is larger than the given target.
 * Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
 * 
 * Examples:
 * Input:
 * letters = ["c", "f", "j"]
 * target = "a"
 * Output: "c"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "c"
 * Output: "f"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "f"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "j"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "c"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "c"
 * Note:
 * 
 * letters has a length in range [2, 10000].
 * letters consists of lowercase letters, and contains at least 2 unique letters.
 * target is a lowercase letter.
 */

char nextGreatestLetter(char* letters, int lettersSize, char target) 
{
 	char res = 0;
 	if(target < 'a' || target > 'z')  return res;
 	if(letterSize < 2) return res;

 	int max = letter[0];
 	for( i = 0; i < letterSize; ++i)
 	{
 		int temp = letters[0] - target;
 		if(temp < max && temp > 0)
 		{
 			max = temp;
 			res = letters[i];
 		}
 	}  

 	if(max == letter[0])
 	{
 		res = letters[0];
 	}

 	return res;
}