/**
 * 	LEETCODE 226. Invert Binary Tree
 */

/**
 * Invert a binary tree.
 * 
 * Example:
 * Input:
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * Output:
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew), 
 * but you can’t invert a binary tree on a whiteboard so f*** off.
 */

TreeNode* invertTree(TreeNode* root) {
    TreeNode* pNode = NULL;
        
    if(root == NULL)
    {
        return pNode;
    }
        
    pNode = root->left;
    root->left = root->right;
    root->right = pNode;
        
    if(root->left != NULL)
    {
        root->left = invertTree(root->left);
    }
        
    if(root->right != NULL)
    {
        root->right = invertTree(root->right);
    }
        
    return root;
        
}