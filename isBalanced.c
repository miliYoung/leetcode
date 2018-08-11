/**
 * 	LEETCODE 110. Balanced Binary Tree
 */

/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example 1:
 * Given the following tree [3,9,20,null,null,15,7]:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 *  Return true.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode* root)
{
     if (root == NULL) {
            return 0;
        } else {
           int left_depth = depth(root->left);
           int right_depth = depth(root->right);
           if (left_depth == -1 || right_depth == -1 || (left_depth - right_depth > 1) || (left_depth - right_depth < -1)) 
                return -1;
           else if (left_depth - right_depth > 0) 
                return left_depth + 1;
           else return right_depth + 1;
        }
}

bool isBalanced(struct TreeNode* root) {
    if(NULL == root)
    {
        return true;
    }
    
    return (depth(root) !=-1);
    
}