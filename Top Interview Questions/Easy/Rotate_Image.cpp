// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
// Time complexity: O(n^2), n = number of columns or rows of matrix
// Space complexity: O(n^2), n = number of columns or rows of matrix

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        // Create another 2D vector with initial values -1 of size nxn
        vector<vector<int>> rotated (matrix.size(), vector<int>(matrix.size(), -1));
        
        // Since the rotated values are the same matrix but 
        // read by columns from bottom to top instead of read by rows left to right
        // We populate the rotated array by reading the matrix by columns from bottom to top
        
        // column: first column to last column, left to right
        for(int j = 0, m = 0; j < matrix.size(); j++, m++)
        {
            // row: last row to first row, bottom to top
            for(int i = matrix.size()-1, n = 0; i >= 0; i--, n++)
            {
                rotated[m][n] = matrix[i][j];
            }
        }
        
        // Copy new rotated value into the original matrix
        matrix = rotated;
    }
};
