/**
 *       LEETCODE 278. First Bad Version
 */

/**
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, 
 * the latest version of your product fails the quality check.Since each version is developed 
 * based on the previous version,all the versions after a bad version are also bad.Suppose you 
 * have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function 
 * to find the first bad version. You should minimize the number of calls to the API.
 * 
 * Example:
 * Given n = 5
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * Then 4 is the first bad version. 
 */

bool isBadVersion(int version);

/**
 * [firstBadVersion description] 查找最早的错误版本号
 * @param  n [description] 版本号范围  
 * @return   [description] 查到的版本号
 */
int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    
    while(right > left)
    {
        int middle = left + (right -left)/2; //note 这里不能直接用(left + right)/2 会存在越界情况
        bool bflag = isBadVersion(middle);
        if(true == bflag)
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
        middle = (left + right)/2;
    }

    return left;
} 