/**
 * 	LEETCODE 572. Subtree of Another Tree
 */

/**
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants.
 * The tree s could also be considered as a subtree of itself.
 * Example 1:
 * Given tree s:
 *     3
 *    / \
 *   4   5
 *  / \
 * 1   2
 * 
 * Given tree t:
 *   4 
 *  / \
 * 1   2
 * 
 * Return true, because t has the same structure and node values with a subtree of s.
 * 
 * Example 2:
 * Given tree s:
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 * /
 * 0
 * 
 * Given tree t:
 *   4
 *  / \
 * 1   2
 * Return false.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isTheSame(struct TreeNode* s, struct TreeNode* t)
{
    //两个数同时到达底端，说明完全相等
    if(s == NULL && t == NULL) return true ;
    
    //当其中有个已到达底端但另一个还没有，返回false
    if((s != NULL && t == NULL) || (s == NULL && t != NULL)) return false ;
    
    //当前val相等，继续对左子树右子树做同样的事，如果都true，则返回true
    if(s->val == t->val && isTheSame(s->left , t->left) && isTheSame(s->right , t->right)) 
        return true ;
    return false ;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) 
{
    //s为空树，或者当s等于NULL时还没找到相等的一个节点，返回false
    if(s == NULL) return false ;
    //找到一个相等节点，如果这个节点以下全都于t相等，返回true
    if(s->val == t->val && isTheSame(s , t)) return true ;
    //否则继续往下寻找是否邮箱等节点，左右子树任意一个找到即可
    else return isSubtree(s->left , t) || isSubtree(s->right , t) ;
    
    return false ;
}

