/**
 * LEETCODE 812. Largest Triangle Area
 */

/**
 * You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
 * 
 * Example:
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2
 * 
 * Explanation: 
 * The five points are show in the figure below. The red triangle is the largest.
 * Notes:
 * 3 <= points.length <= 50.
 * No points will be duplicated.
 * -50 <= points[i][j] <= 50.
 * Answers within 10^-6 of the true value will be accepted as correct.
 */

double largestTriangleArea(int** points, int pointsRowSize, int *pointsColSizes) {
    
    if(NULL == points || pointsRowSize < 3)
    {
        return 0;
    }
    
    int i = 0;
    int j = 0;
    int k = 0;
    double area = 0;
    double max_area = 0;
    for( i = 0; i < pointsRowSize; ++i)
    {
        for(j = 0; j < pointsRowSize; ++j)
        {
            for(k = 0; k < pointsRowSize; ++k)
            {
                area = 0.5 * (points[i][0]*points[j][1]+ points[j][0]*points[k][1]+points[k][0]*points[i][1] -
                             points[i][0]*points[k][1] - points[j][0]*points[i][1] -points[k][0]*points[j][1]);
                    
                max_area = max_area > area ? max_area : area;
            }
        }
    }
    
    return max_area;   
}