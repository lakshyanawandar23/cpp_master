class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        int j=0;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end()){
                ans[mp[s]].push_back(strs[i]);
            }
            else{
                vector<string> v;
                v.push_back(strs[i]);
                ans.push_back(v);
                mp[s]=j;
                j++;
            }
        }
        return ans;
    }
};