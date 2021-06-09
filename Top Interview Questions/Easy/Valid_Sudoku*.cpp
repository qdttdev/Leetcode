// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/
// Time complexity: O(n^2), n = size of board row or col
// Space complexity: O(3n^2) = O(n^2), n = size of board row or col

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        set<char> setRow;
        set<char> setCol;
        set<char> setSquare;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                // More explaination on how to compute m and n: earlme's explanation
                // https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/discuss/15450/Shared-my-concise-Java-code
                
                // Essentially, we're mapping 9x9 matrix into 3x3 matrix
                
                // m = rowIndex and n = colIndex for square traversal
                // Use i to move to the next square
                // Multiply by 3 so that next square is after 3 columns
                // So (0,0) --> (0,3)                
                int m = 3*(i/3);
                int n = 3*(i%3);

                // Since j iterates from 0-9:
                // Use j/3 for rows --> 0/3 = 0, 1/3 = 0, 2/3 = 0, 3/3 = 1
                // Use j%3 for columns --> 0%3 = 0, 1%3 = 1, 2%3 = 2
                m = m + j/3;
                n = n + j%3;

                if( (setRow.find(board[i][j]) != setRow.end())
                ||  (setCol.find(board[j][i]) != setCol.end())
                ||  (setSquare.find(board[m][n]) != setSquare.end()) )
                {
                    return false;
                }
                else
                {
                    if(board[i][j] != '.')
                    {
                        setRow.insert(board[i][j]);
                    }
                    if(board[j][i] != '.')
                    {
                        setCol.insert(board[j][i]);
                    }
                    if(board[m][n] != '.')
                    {
                        setSquare.insert(board[m][n]);
                    }
                }
            }

            // Reset sets to check for new rows/ columns/ squares
            setRow.clear();
            setCol.clear();
            setSquare.clear();
        }

        return true;
    }
};
