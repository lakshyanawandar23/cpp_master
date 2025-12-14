class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        unordered_map<int, pair<int,int>> mp1, mp2;

        for (auto &it : b) {
            int x = it[0];
            int y = it[1];

            if (mp1.find(x) == mp1.end())
                mp1[x] = {INT_MAX, INT_MIN};
            if (mp2.find(y) == mp2.end())
                mp2[y] = {INT_MAX, INT_MIN};

            mp1[x].first = min(mp1[x].first, y);
            mp1[x].second = max(mp1[x].second, y);

            mp2[y].first = min(mp2[y].first, x);
            mp2[y].second = max(mp2[y].second, x);
        }

        int ans = 0;
        for (auto &it : b) {
            int x = it[0];
            int y = it[1];

            if (mp1[x].first < y && mp1[x].second > y &&
                mp2[y].first < x && mp2[y].second > x) {
                ans++;
            }
        }
        return ans;
    }
};
