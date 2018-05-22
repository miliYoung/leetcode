/**
 * 	Third Maximum Number 
 */

/**
 * Given a non-empty array of integers, return the third maximum number in this array. 
 * If it does not exist, return the maximum number. The time complexity must be in O(n).
 * 
 * Example 1:
 * Input: [3, 2, 1]
 * Output: 1
 * Explanation: The third maximum is 1.
 * 
 * Example 2:
 * Input: [1, 2]
 * Output: 2
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 */


#define INT_MAX		((int)(~0U>>1))
#define INT_MIN		(-INT_MAX - 1)

/**
 * [swap description]   交换两个数字
 * @param a [description] 待交换的参数a
 * @param b [description] 待交换的参数b
 */
void swap(int* a, int* b)
{
	int temp = 0;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * [thirdMax description]   找出数组中第三大的数字
 * @param  nums     [description] 数组
 * @param  numsSize [description] 数组大小
 * @return          [description] 数组中第三大的元素
 */
int thirdMax(int* nums, int numsSize) {
    if(NULL == nums || numsSize == 0)
	{
		return 0;
	}
	int i = 0;
	int a[3] = {INT_MIN,INT_MIN,INT_MIN};
	int temp = 0;
	bool bflag = false;
	for(i = 0; i < numsSize; ++i)
	{
		if(nums[i] == INT_MIN)
		{
			bflag = true;	
		}
		
		if(nums[i] > a[0])
		{	
			swap(a +1,a + 2);
			swap(a ,a + 1);
			a[0] = nums[i];
		}
		else if(nums[i] < a[0] && nums[i] > a[1])
		{
			swap(a + 1, a + 2);
			a[1] = nums[i];
		}
		else if(nums[i] < a[1] && nums[i] > a[2])
		{	
			a[2] = nums[i];
		}
		else
		{
			continue;
		}
	}
	
	if(a[2] == INT_MIN && a[1] == INT_MIN )
	{
		return a[0];
	}
	
	if(a[2] == INT_MIN && bflag == false && a[1] != INT_MIN)
	{
		return a[0];
	}
	
	return a[2];
}
