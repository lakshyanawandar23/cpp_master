class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), ans = 1;

        vector<vector<int>> row_pre(n, vector<int>(m, 0));
        vector<vector<int>> col_pre(n, vector<int>(m, 0));

        // Row prefix sum
        for (int i = 0; i < n; i++) {
            row_pre[i][0] = g[i][0];
            for (int j = 1; j < m; j++) {
                row_pre[i][j] = row_pre[i][j - 1] + g[i][j];
            }
        }

        // Column prefix sum
        for (int j = 0; j < m; j++) {
            col_pre[0][j] = g[0][j];
            for (int i = 1; i < n; i++) {
                col_pre[i][j] = col_pre[i - 1][j] + g[i][j];
            }
        }

        // Try all top-left corners
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Try square sizes
                for (int k = 1; i + k < n && j + k < m; k++) {

                    bool ok = true;
                    int target = -1;

                    // Check rows
                    for (int r = i; r <= i + k; r++) {
                        int sum = row_pre[r][j + k] - (j > 0 ? row_pre[r][j - 1] : 0);
                        if (target == -1) target = sum;
                        else if (sum != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    // Check columns
                    for (int c = j; c <= j + k; c++) {
                        int sum = col_pre[i + k][c] - (i > 0 ? col_pre[i - 1][c] : 0);
                        if (sum != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    // Check main diagonal
                    int diag1 = 0;
                    for (int d = 0; d <= k; d++)
                        diag1 += g[i + d][j + d];

                    // Check anti-diagonal
                    int diag2 = 0;
                    for (int d = 0; d <= k; d++)
                        diag2 += g[i + d][j + k - d];

                    if (diag1 == target && diag2 == target)
                        ans = max(ans, k + 1);
                }
            }
        }

        return ans;
    }
};
