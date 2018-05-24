/**
 * 	LEETCODE	190. Reverse Bits
 */

/**
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Example:
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
 * 
 * return 964176192 represented in binary as 00111001011110000010100101000000.
 */

/**
 * [reverseBits description] 按位进行反转
 * @param  n [description]   待反转的数字
 * @return   [description]   翻转后的结果
 * @note 可以考虑用移位进行反转
 */
uint32_t reverseBits(uint32_t n) 
{
	uint32_t res = 0;
    int i = sizeof(uint32_t) * 8;
    while( i > 0 )
    {
        res = res *2 + (n % 2);
        n = n/2;
        i--;
    }
        
    return res;
}