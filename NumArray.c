/**
 * 	LEETCODE 303. Range Sum Query - Immutable
 */

/**
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * 
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.There are many calls to sumRange function.
 */

typedef struct {
    int* data;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* pArray = malloc(sizeof(NumArray));
    if(NULL == pArray)
    {
        return pArray;
    }
    else
    {
        memset(pArray, 0, sizeof(NumArray));
    }
    
    pArray->data = nums;
    pArray->size = numsSize;
    
    return pArray;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if(NULL == obj)
    {
        return 0;
    }
    
    if(obj->size < j)
    {
        j = obj->size;
    }
    
    if(i < 0)
    {
        i = 0;
    }
    
    int sum = 0;
    int k = 0;
    for(k = i; k <= j; k++)
    {
        sum = sum + obj->data[k];
    }
    
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */