class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {

        int i = 0;
        int j = g[0].size() - 1;
        int row = g.size() - 1;

        while (i < j && i < row) {

            int size = ((row - i + 1) * 2) + ((j - i + 1) * 2) - 4;

            int tmp = k % size;

            while (tmp--) {

                // your cyclic logic
                int curr = g[i][j];
                int next;

                // move top row
                for (int x = j; x > i; x--) {
                  //  curr = g[i][x];
                    next = g[i][x - 1];
                    g[i][x - 1] = curr;
                    curr = next;
                }

                // move first column
                for (int x = i + 1; x <= row; x++) {
                    next = g[x][i];
                    g[x][i] = curr;
                    curr = next;
                }

                // move bottom row
                for (int x = i + 1; x <= j; x++) {
                    next = g[row][x];
                    g[row][x] = curr;
                    curr = next;
                }

                // move last column
                for (int x = row - 1; x >= i; x--) {
                    next = g[x][j];
                    g[x][j] = curr;
                    curr = next;
                }
            }

            i++;
            j--;
            row--;
        }

        return g;
    }
};