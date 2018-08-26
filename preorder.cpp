/**
 * LEETCODE 589. N-ary Tree Preorder Traversal
 */

/**
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * For example, given a 3-ary tree:
 * 		1
 * 	  / | \
 * 	 3  2  4
 * 	/ \
 * 6   5
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> vec_int;
        if(NULL == root)
        {
            return vec_int;
        }
        
        traverse(vec_int, root);
        
        return vec_int;
    }
    
    void traverse(vector<int>& vec_int, Node* root)
    {
        if(root == NULL)
        {
            return ;
        }
        
        vec_int.push_back(root->val);
        
        vector<Node*>::iterator iter;
        for(iter = root->children.begin(); iter != root->children.end(); ++iter)
        {
             traverse(vec_int, (*iter));
        }
    }
};