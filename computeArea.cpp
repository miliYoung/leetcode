/**
 * LEETCODE 223. Rectangle Area
 */

/**
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * 
 * Rectangle Area
 * 
 * Example:
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note: Assume that the total area is never beyond the maximum possible value of int.
 */

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int area = (D - B) * (C - A) + (G - E) * (H - F); // 总面积
 
		int left = max(A, E);
		int down = max(B, F);
 
		int right = min(G, C);
		int up = min(D, H);
 
		if (up <= down || right <= left) {
			return area;
		}
 
		area = area - (right - left) * (up - down);
 
		return area;
    };
    
    int max(int a, int b)
    {
        return a > b ? a:b;
    };
    
     int min(int a, int b)
    {
        return a < b ? a:b;
    };
};