/**
 * LEETCODE 728. Self Dividing Numbers
 */

/**
 * A self-dividing number is a number that is divisible by every digit it contains.
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * Given a lower and upper number bound, output a list of every possible self dividing number, 
 * including the bounds if possible.
 * 
 * Example 1:
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * Note:
 * The boundaries of each input argument are 1 <= left <= right <= 10000.
 */

int* selfDividingNumbers(int left, int right, int* returnSize) 
{
    if(left < 1 && left > right && right > 10000)
    {
        return NULL;
    }   

    int*  presult = malloc(sizeof(int) * right);
    *returnSize = 0;
    for(int inum = left; inum <= right; ++inum)
    {
        int itemp = inum;
        bool bflag = true;
        while(itemp > 0)
        {
            int res = itemp % 10;
            itemp = itemp/10;
            if(res == 0 || inum % res != 0)
            {
                bflag = false;
                break;
            }
        }
            
        if(true == bflag)
        {
            presult[*returnSize] = inum;
            *returnSize++;
        }
    }

    return presult;
}

/**
 * 该方法可以改进，通过实时计算数组的大小进行重构
 */