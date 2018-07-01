/**
 * 	LEETCODE 412. Fizz Buzz
 */

/**
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
 * For numbers which are multiples of both three and five output “FizzBuzz”.
 * 
 * Example:
 * n = 15,
 * Return:
 * [
 *  "1",
 *   "2",
 *   "Fizz",
 *   "4",
 *   "Buzz",
 *   "Fizz",
 *   "7",
 *   "8",
 *   "Fizz",
 *   "Buzz",
 *   "11",
 *   "Fizz",
 *   "13",
 *   "14",
 *   "FizzBuzz"
 *   ]
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) 
{
 	if(n == 0)
 	{
 		return NULL;
 	}   

 	char** res = malloc( n * sizeof(char*));
 	if(NULL == res)
 	{
 		return NULL;
 	}

 	for (int i = 1; i <= n; ++i)
	{
		char* temp = NULL;
        if(i%3 == 0 && i%5 == 0)
        {
             temp = "FizzBuzz";
        }
		else if (i % 3 == 0)
		{
			temp = "Fizz";
		}
		else if (i % 5 == 0)
		{
			temp = "Buzz";
		}
		else
		{
			temp = itoa(i);	    
		} 
		*(res+i) = malloc(strlen(temp));
		*(res+i) = temp;
	}

	*returnSize = i;

	return res;
}