// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/

// Currently: 473/507 test cases passed

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        set<char> setRow;
        set<char> setCol;
        set<char> setSquare;

        // CHECK FOR UNIQUENESS OF ROWS
        // row
        for(int i = 0; i < board.size(); i++)
        {
            // col
            for(int j = 0; j < board.size(); j++)
            {
                if(setRow.find(board[i][j]) != setRow.end())
                {
                    return false;
                }
                else
                {
                    if(board[i][j] != '.')
                    {
                        setRow.insert(board[i][j]);
                    }

                }
            }

            setRow.clear();
        }

        // CHECK FOR UNIQUENESS OF COLUMNS
        // col
        for(int j = 0; j < board.size(); j++)
        {
            // row
            for(int i = 0; i < board.size(); i++)
            {
                if(setCol.find(board[i][j]) != setCol.end())
                {
                    return false;
                }
                else
                {
                    if(board[i][j] != '.')
                    {
                        setCol.insert(board[i][j]);
                    }

                }
            }

            setCol.clear();
        }

        // CHECK FOR UNIQUENESS OF SQUARES
        // square
        int i = 0;
        int j = 0;

        for(int c = 0; c < 9; c++)
        {
            for(int m = i; m < 3; m++) // row
            {
                for(int n = j; n < 3; n++) // col
                {
                    if(setSquare.find(board[m][n]) != setSquare.end())
                    {
                        return false;
                    }
                    else
                    {
                        if(board[m][n] != '.')
                        {
                            setSquare.insert(board[m][n]);
                        }                          
                    }
                }

                setSquare.clear();
            }

            j = j + 3;
            if(j == 6)
            {
                i = i + 3;
                j = 0;
            }
        }

        return true;
    }
};
