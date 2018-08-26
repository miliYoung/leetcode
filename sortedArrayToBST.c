/**
 * LEETCODE 108. Convert Sorted Array to Binary Search Tree
 */

/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Example:
 * Given the sorted array: [-10,-3,0,5,9],
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *      0
 *     / \
 *   -3   9
 *   /   /
 * -10  5
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* toBST(int* nums, int start, int end)
{
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    if(start == end)
    {
        root->val = nums[start];
    }
    
    if(start > end)
    {
        return NULL;
    }
    
    int mid = (start) + (end - start)/2;
    root->val = nums[mid];
    root->left = toBST(nums,start, mid - 1);
    root->right = toBST(nums, mid+1, end);
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
    {
        return NULL;
    }
    
    int mid = (0 + numsSize - 1)/2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = toBST(nums,0,mid - 1);
    root->right = toBST(nums, mid+1, numsSize - 1);
    
    return root;
}