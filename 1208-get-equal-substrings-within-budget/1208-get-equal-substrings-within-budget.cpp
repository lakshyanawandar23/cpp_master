class Solution {
public:
    int equalSubstring(string s, string t, int c) {
        int ans=0,cnt=0,res=0,j=0,i=0;
        vector<int>v;
        for(int i=0;i<s.size();i++){
           cnt=abs(s[i]-t[i]);
            v.push_back(cnt);
        }
        while(j<t.size()){
            while(j<t.size()&&res<=c){
                res+=v[j];
                if(res<=c){
            ans=max(ans,(j-i+1));}
                j++;
            }
        while(i<j&&res>c){
            res-=v[i];
            i++;
        }
            
        }
        return ans>0?ans:0;
    }
};