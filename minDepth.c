/**
 * LEETCODE 111. Minimum Depth of Binary Tree
 */

/**
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * Example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its minimum depth = 2.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    
     if (NULL == root)
     {
         return 0;
     }    
     int l = minDepth(root->left);
     int r = minDepth(root->right);
     if (!l)
         return r+1;
    if (!r)
        return l+1;
    
    return (l<r)?l+1:r+1;
}