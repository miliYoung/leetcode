/**
 *  LEETCODE 101. Symmetric Tree
 */

/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *      1
 *     / \
 *    2   2
 *   / \ / \
 *  3  4 4  3
 *  But the following [1,2,2,null,3,null,3] is not:
 *    1
 *   / \
 *  2   2
 *   \   \
 *   3    3
 *   
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool mirror (struct TreeNode* n1, struct TreeNode* n2)
{
    if (n1 == NULL || n2 == NULL) 
    {
        return n1 == n2;
    }
    
    return n1->val == n2->val && mirror(n1->left, n2->right) && mirror(n1->right, n2->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL) return true;
    {
        return mirror (root->left, root->right);
    }
}
    
