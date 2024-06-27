class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        int n=e.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++ ){
            mp[e[i][0]]++;
            mp[e[i][1]]++;
        }
        int m=mp.size()-1;
        for(auto it:mp){
            if(it.second==m) return it.first;
        }
        return -1;
    }
};