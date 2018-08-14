/**
 * 	LEETCODE 872. Leaf-Similar Trees
 */

/**
 * Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void leaf(struct TreeNode* root, char* res)
{
    if(NULL == root || NULL == res)
    {
        return ;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        res[strlen(res)] = root->val;
        return;
    }
    
    if(root->left != NULL)
    {
        leaf(root->left, res);
    }
    
    if(root->right != NULL)
    {
        leaf(root->right, res);
    }
    
    return ;
    
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    
    if(NULL == root1 && NULL != root2) return false;
    if(NULL != root1 && NULL == root2) return true;
    
    char* res1 = malloc(4 * 1024);
    if(NULL != res1)
    {
         memset(res1, 0 , 4 * 1024);   
    }
    else
    {
        return false;
    }
    
    char* res2 = malloc(4 * 1024);
    if(NULL != res2)
    {
         memset(res2, 0 , 4 * 1024);   
    }
    else
    {
        free(res1);
        return false;
    }
    
    leaf(root1,res1);
    leaf(root2,res2);
    
    int len1 = strlen(res1);
    int len2 = strlen(res2);
    if(len1 != len2)
    {
        free(res1);
        free(res2);
        return false;
    }
    
    if(strncmp(res1, res2, len1) == 0)
    {
        free(res1);
        free(res2);
        return true;
    }   
    else
    {
        free(res1);
        free(res2);
        return false; 
    }
}