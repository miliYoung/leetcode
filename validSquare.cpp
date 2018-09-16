/**
 * LEETCODE 593. Valid Square
 */

/**
 * Given the coordinates of four points in 2D space, return whether the four points could construct a square.
 * The coordinate (x,y) of a point is represented by an integer array with two integers.
 * 
 * Example:
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 * 
 * Note:
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal angles (90-degree angles).
 * Input points have no order.
 */

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int len[7] = {0};
        
        len[0] = calSideLen(p1,p2);
        len[1] = calSideLen(p1,p3);
        len[2] = calSideLen(p1,p4);
        len[3] = calSideLen(p2,p3);
        len[4] = calSideLen(p2,p4);
        len[5] = calSideLen(p3,p4);
        
        sort(len,len+6);
        
        if(len[0] == 0) return false;
        
        
        if(len[0] != len[1] || len[1] != len[2] || len[2] != len[3])
        {
            return false;
        }
        
        if(len[4] != len[5])
        {
            return false;
        }
        
        if(len[4] != 2 * len[0])
        {
            return false;
        }
        
        return true;
        
    }
    
    int calSideLen(vector<int> p1, vector<int> p2)
    {
        if( p1.size()!= 2 || p2.size() != 2 )
        {
            return 0;
        }
        
        int len = 0;
        len  = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        
        return len;
    }
};