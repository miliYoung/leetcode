/**
 *  LEETCODE 559. Maximum Depth of N-ary Tree
 */

/**
 * Given a n-ary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * For example, given a 3-ary tree:
 * 				1
 * 			  / | \
 * 		     3	2  4
 * 		    / \
 * 		   2   6
 * We should return its max depth, which is 3.
 * Note:
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 */

class Solution {
public:
    int maxDepth(Node* root) {
        
        if(!root){
            return 0;
        }
        int depth = 0;

        vector<Node*>::iterator iter = root->children.begin();
        for(; iter != root->children.end(); ++iter){
            int r = maxDepth(*iter);
            if(r > depth){
                depth = r;
            }
        }
        return depth + 1;
    }
};