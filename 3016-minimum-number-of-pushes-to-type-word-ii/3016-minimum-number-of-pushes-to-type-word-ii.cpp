class Solution {
public:
    int minimumPushes(string w) {
        int ans=0,cnt=0;
        vector<int>v(26,0);
        for(auto it:w){
            if(it>='a'&&it<='z'){
                v[it-'a']++;
            }
            else{
                cnt++;
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<26;i++){
            ans+=((i/8+1)*(v[i]));
        }
        return cnt+ans;
    }
};