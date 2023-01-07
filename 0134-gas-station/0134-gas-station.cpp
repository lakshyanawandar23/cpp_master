class Solution {
public:
    int canCompleteCircuit(vector<int>&s, vector<int>& c) {
        int ans=0,res=0;
        for(int i=0;i<c.size();i++){
            ans+=s[i];
            res+=c[i];
        }
        if(ans<res){
            return -1;
        }
        int st=0,curr=0;
        for(int i=0;i<c.size();i++){
            if(curr<0){
                st=i;
                curr=0;
            }
            curr+=s[i]-c[i];
        }
        return st;
    }
};