class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        for(auto it:arr1){
            string s=to_string(it);
            for(int i=0;i<s.size();i++){
                mp1[s.substr(0,i+1)]++;
            }
        }
         for(auto it:arr2){
            string s=to_string(it);
            for(int i=0;i<s.size();i++){
                mp2[s.substr(0,i+1)]++;
            }
        }
        int ans=0;
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                int size=it.first.size();
                ans=max(ans,size);
            }
        }
        return ans;
    }
};