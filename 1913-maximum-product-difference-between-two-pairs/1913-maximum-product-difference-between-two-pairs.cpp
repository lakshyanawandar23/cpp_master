class Solution {
public:
    int maxProductDifference(vector<int>& num) {
        sort(num.begin(),num.end());
        int n=num.size();
        return abs((num[0]*num[1])-(num[n-1]*num[n-2]));
    }
};