class Solution {
public:
    const int mod = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> v;
        for (int i = 0; n > 0; i++, n >>= 1) {
            if (n & 1) v.push_back(1 << i);
        }

        vector<long long> pre(v.size());
        pre[0] = v[0];
        for (int i = 1; i < v.size(); i++)
            pre[i] = (pre[i - 1] * v[i]) % mod;

        vector<int> ans;
        for (auto &query : q) {
            int l = query[0], r = query[1];
            long long res = pre[r];
            if (l > 0) res = (res * modPow(pre[l - 1], mod - 2)) % mod;
            ans.push_back(res);
        }
        return ans;
    }
};
