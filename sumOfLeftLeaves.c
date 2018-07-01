/**
 * 	LEETCODE 404. Sum of Left Leaves
 */

/**
 * Find the sum of all left leaves in a given binary tree.
 * Example:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 *
 *There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    
    int res = 0;
    
    if(NULL == root)
    {
        return 0;
    }
    int left_index = 0;
    int right_index = 0;
    
    if(root->left != NULL)
    {
        if(root->left->left == NULL && root->left->right == NULL) 
        {
            left_index = root->left->val;
        }
        else
        {
            left_index = sumOfLeftLeaves(root->left);
        }
    }
    
    right_index = sumOfLeftLeaves(root->right);
    
    return right_index + left_index;
    
}