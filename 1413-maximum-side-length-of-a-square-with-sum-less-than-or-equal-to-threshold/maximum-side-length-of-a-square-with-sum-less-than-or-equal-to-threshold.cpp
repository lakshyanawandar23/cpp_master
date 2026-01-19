class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size(), ans = 0;

        // Prefix sum
        vector<vector<int>> pre(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = mat[i][j]
                          + (i > 0 ? pre[i - 1][j] : 0)
                          + (j > 0 ? pre[i][j - 1] : 0)
                          - (i > 0 && j > 0 ? pre[i - 1][j - 1] : 0);
            }
        }

        // Try every top-left corner
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Try square sizes
                for (int len = 1;
                     i + len - 1 < n && j + len - 1 < m;
                     len++) {

                    int r2 = i + len - 1;
                    int c2 = j + len - 1;

                    int sum = pre[r2][c2]
                            - (i > 0 ? pre[i - 1][c2] : 0)
                            - (j > 0 ? pre[r2][j - 1] : 0)
                            + (i > 0 && j > 0 ? pre[i - 1][j - 1] : 0);

                    if (sum <= t)
                        ans = max(ans, len);
                    else
                        break; // larger square will only increase sum
                }
            }
        }

        return ans;
    }
};
