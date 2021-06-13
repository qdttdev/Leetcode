// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/
// Time complexity: O(n^2), n = size of board row or col
// Space complexity: O(3n^2) = O(n^2), n = size of board row or col

// Question: Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// 1. Each row must contain the digits 1-9 without repetition.
// 2. Each column must contain the digits 1-9 without repetition.
// 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Approach: Use the rules to check for validity of the sudoku but I was stuck at checking for rule #3.
// This problem was not easy for me, I needed to check for clues on the Discussion.
// My understanding for the use of i/3 and i%3 is still a blur, will need to come back to this problem.

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
