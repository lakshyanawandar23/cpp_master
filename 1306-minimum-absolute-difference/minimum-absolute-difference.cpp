class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=1;i<arr.size();i++){
        ans=min(ans,abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>>v;
        for(int i=1;i<arr.size();i++){
            vector<int>res;
            int diff=abs(arr[i]-arr[i-1]);
            if(diff==ans){
                res.push_back(arr[i-1]);
                res.push_back(arr[i]);
                v.push_back(res);
            }
        }
        return v;
    }
};