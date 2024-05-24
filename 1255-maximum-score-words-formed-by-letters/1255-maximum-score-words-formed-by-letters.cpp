class Solution {
public:
    int cnt;
    int solve(vector<string>&w,vector<char>&l,vector<int>&s,unordered_map<char,int>&mp,int i){
        if(i==w.size()){
           return 0; 
        }
        int pick=0,no=0,j=0,ans=0;
        bool flag=false;
        no=0+solve(w,l,s,mp,i+1);
        for( j=0;j<w[i].size();j++){
            if(mp[w[i][j]]>0){
                mp[w[i][j]]--;
                ans+=s[w[i][j]-'a'];
                flag=true;
            }
            else {
                break;
            }
        }
        if(j==w[i].size()){
          //  cout<<ans<<endl;
            pick=ans+solve(w,l,s,mp,i+1);
        }
        if(flag){
            for(int k=0;k<j;k++){
                mp[w[i][k]]++;
            }
        }
        return max(no,pick);
    }
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        cnt=0;
        unordered_map<char,int>mp;
        for(auto it:l){
        mp[it]++;
        }
        return  solve(w,l,s,mp,0);
    }
};