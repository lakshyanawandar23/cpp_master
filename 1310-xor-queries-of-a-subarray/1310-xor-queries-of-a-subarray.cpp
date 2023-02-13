class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int>ans;
        vector<int>res(arr.size());
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            int x=cnt^arr[i];
           // cout<<x<<endl;
            res[i]=x;
            cnt=res[i];
        }
        for(auto val:q){
            int l=val[0];
            int r=val[1];
            int x=res[r];
            if(l>0){
                x=res[l-1]^res[r];
            }
            ans.push_back(x);
        }
        return ans;
    }
};