/*
Problem: N-Queens
Problem Number: 51
Difficulty: Hard
Topic: arrays
Date: 2026-03-25

Approach:
Use backtracking row by row, placing one queen per row while tracking occupied columns and diagonals to ensure no conflicts.
Maintain three boolean arrays for columns, main diagonals (r-c), and anti-diagonals (r+c) so each placement/rollback is O(1).
Store the chosen column per row and, upon reaching row n, construct the board strings for one valid arrangement.

Time Complexity: O(N!) in the search space (pruned by constraints; each node does O(1) work plus O(N^2) to output each solution)
Space Complexity: O(N) auxiliary for recursion and state (excluding output)
*/

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        if (n <= 0) return res;

        // cols[c] = whether a queen is already placed in column c
        std::vector<char> cols(n, 0);
        // diag1[d] for main diagonals (r - c + (n-1)) in [0 .. 2n-2]
        std::vector<char> diag1(2 * n - 1, 0);
        // diag2[d] for anti-diagonals (r + c) in [0 .. 2n-2]
        std::vector<char> diag2(2 * n - 1, 0);

        // pos[r] = chosen column for row r
        std::vector<int> pos(n, -1);

        auto buildBoard = [&](void) -> std::vector<std::string> {
            std::vector<std::string> board(n, std::string(n, '.'));
            for (int r = 0; r < n; ++r) board[r][pos[r]] = 'Q';
            return board;
        };

        std::function<void(int)> dfs = [&](int r) {
            if (r == n) {
                res.push_back(buildBoard());
                return;
            }
            for (int c = 0; c < n; ++c) {
                int d1 = r - c + (n - 1);
                int d2 = r + c;
                if (cols[c] || diag1[d1] || diag2[d2]) continue;

                // Place queen
                cols[c] = diag1[d1] = diag2[d2] = 1;
                pos[r] = c;

                dfs(r + 1);

                // Remove queen (backtrack)
                pos[r] = -1;
                cols[c] = diag1[d1] = diag2[d2] = 0;
            }
        };

        dfs(0);
        return res;
    }
};