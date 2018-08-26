/**
 * LEETCODE 590. N-ary Tree Postorder Traversal
 */

/**
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 		1
 *    / | \   
 *   3  2  4
 *  / \
 * 5   6
 * Return its postorder traversal as: [5,6,3,2,4,1].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> vec_int;
        if(NULL == root)
        {
            return vec_int;
        }
        
        putIndex(vec_int,root);
        
        return vec_int;
    }
    
    void putIndex(vector<int>& vec_int,Node* root)
    {
        if(NULL == root)
        {
            return;
        }
           
        
        vector<Node*>::iterator iter;
        for(iter = root->children.begin(); iter != root->children.end(); ++iter)
        {
            putIndex(vec_int,(*iter));
        }
        
        vec_int.push_back(root->val);
    }
};