#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int row, int col, vector<vector<char>> board)
    {
        int n = board.size();
        // checking row
        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
                return false;
        }

        // top left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        // bottom left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void solve(int col, int n, vector<vector<char>> board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            vector<string> temp;
            string s = "";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < board[i].size(); j++)
                {
                    s += board[i][j];
                }
                temp.push_back(s);
                s = "";
            }
            ans.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(i, col, board))
            {
                board[i][col] = 'Q';
                solve(col + 1, n, board, ans);
                board[i][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(0, n, board, ans);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(4);
    
    for (auto i: ans)
    {
        for(auto j:i) {
            cout<<j<<endl;
        }cout<<endl;
    }
    

    return 0;
}