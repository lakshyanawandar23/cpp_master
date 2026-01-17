class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        //basically a gemotery probelm
                long long int ans = 0;
        for (int i = 0; i < b.size(); i++) {
            for (int j = i + 1; j < b.size(); j++) {
                int minX = std::max(b[i][0], b[j][0]);
                int minY = std::max(b[i][1], b[j][1]);
                int maxX = std::min(t[i][0], t[j][0]);
                int maxY = std::min(t[i][1], t[j][1]);

                if (minX < maxX && minY < maxY) {
                    long long side = std::min(maxX - minX, maxY - minY);
                    ans = max(ans, side * side);
                }
            }
        }

        return ans;
    }
};