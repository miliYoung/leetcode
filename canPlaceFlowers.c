/**
 * 	LEETCODE 605. Can Place Flowers
 */

/**
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, 
 * flowers cannot be planted in adjacent plots - they would compete for water and both would die.
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 * 
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * 
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * 
 * Note:
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 */

/**
 * [canPlaceFlowers description] 判断花田是否适合种植
 * @param  flowerbed     [description] 表示花田的数组，1表示已经种植花，0表示未种植
 * @param  flowerbedSize [description] 花田的大小
 * @param  n             [description] 需要中间空闲的花田
 * @return               [description] true表示适合种植，false表示不适合种植
 */

/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int bool;
#define false 0;
#define true 1;*/

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if(NULL == flowerbed || 0 == flowerbedSize || 0 == n)
    {
        return false;
    }

    if(n >= flowerbedSize - 1)
    {
    	return false;
    }

    int i = 0, j = 0;
    for(i = 0; i < flowerbedSize;)
    {
        j = 1;
        if(*(flowerbed+i) == 1 )
        {
            for(; j < n+1 && i+j <= flowerbedSize - 1; j++)
            {
                if(*(flowerbed+i+j) != 0)
                {
                    return false;
                }
            }
        }
        if(*(flowerbed+i+j) == 0)
        {
        	*(flowerbed+i+j) = 1;
        }
        i = i+j;
    }
    
    return true;
}


/*int main()
{
	int flowerbed[] = {1,0,0,0,1};
	bool bflag = canPlaceFlowers(flowerbed,sizeof(flowerbed)/sizeof(int),5);

	printf("bflag = %d\n",bflag);
	return 0;
}*/